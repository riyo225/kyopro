#include <bits/stdc++.h>
using namespace std;

const int dr[] = {1, 0, -1, 0};
const int dc[] = {0, 1, 0, -1};

struct Point {
    int r, c;
};

struct Params {
    // 評価関数の重みづけ
    const long long EMPTY_BONUS = 20000;
    const long long MY_ESSENTIAL_BONUS = 40000;
    const long long ENEMY_ESSENTIAL_BONUS = 15000;
    const long long CORNER_BONUS = 10000;
    const long long EDGE_BONUS = 4000;
    
    // ペナルティ
    const long long LEVEL_MAX_PENALTY = -1e18;
    const long long COLLISION_PENALTY = -50000;

    // ビームサーチ
    const int beam_width = 500;
    const int depth = 15;
};

struct AIParams {
    double wa = 1.0;
    double wb = 1.0;
    double wc = 1.0;
    double wd = 1.0;
    double eps = 1.0;
};

struct Node {
    int r, c;
    long long score;
    int first_move_r, first_move_c;
};

struct State {
    int N, M, T, U;
    vector<vector<long long>> V;
    vector<vector<int>> O, L;
    vector<pair<int, int>> pos;
    int cur_r, cur_c;

    chrono::steady_clock::time_point start_time;

    Params param;

    vector<vector<Point>> player_islands;
    vector<int> player_scores;
    vector<int> player_ranks;
    vector<pair<long long, int>> sorted_scores;

    vector<vector<long long>> score_cache;

    vector<AIParams> ai_params;
    vector<Point> ai_targets;

    int dist_to_top;

    void initial() {
        cin >> N >> M >> T >> U;
        V.assign(N, vector<long long>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cin >> V[i][j];
        }
        vector<pair<int, int>> s(M);
        for (int i = 0; i < M; i++) cin >> s[i].first >> s[i].second;
        O.assign(N, vector<int>(N, -1));
        L.assign(N, vector<int>(N, 0));
        for (int i = 0; i < M; i++) {
            O[s[i].first][s[i].second] = i;
            L[s[i].first][s[i].second] = 1;
        }
        pos = s;
        cur_r = pos[0].first;
        cur_c = pos[0].second;
        ai_params.assign(M, AIParams());
    }

    void update() {
        vector<pair<int, int>> target(M);
        for (int i = 0; i < M; i++) cin >> target[i].first >> target[i].second;
        for (int i = 0; i < M; i++) cin >> pos[i].first >> pos[i].second;
        cur_r = pos[0].first;
        cur_c = pos[0].second;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cin >> O[i][j];
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cin >> L[i][j];
        }
    }

    vector<vector<bool>> get_reachable_map(int r, int c, int person) {
        vector<vector<bool>> reachable(N, vector<bool> (N, false));
        queue<Point> que;

        que.push({r, c});
        reachable[r][c] = true;

        while (!que.empty()) {
            Point p = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nr = p.r + dr[i];
                int nc = p.c + dc[i];
                if (nr >= 0 && nr < N && nc >= 0 && nc < N && !reachable[nr][nc] && O[nr][nc] == person) {
                    reachable[nr][nc] = true;
                    que.push({nr, nc});
                }
            }
        }
        return reachable;
    }

    // 連結性のチェック
    bool is_essential(int r, int c, int person, const vector<Point>& island) {
        if (O[r][c] != person) return false;
        if (island.size() <= 1) return false;

        Point start = (island[0].r == r && island[0].c == c) ? island[1] : island[0];
        int reachable_count = 0;

        vector<vector<bool>> visited(N, vector<bool> (N, false));
        queue<Point> que;

        que.push(start);
        visited[start.r][start.c] = true;
        reachable_count++;

        while (!que.empty()) {
            Point p = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nr = p.r + dr[i];
                int nc = p.c + dc[i];
                if (nr >= 0 && nr < N && nc >= 0 && nc < N && !visited[nr][nc] && O[nr][nc] == person) {
                    if (nr == r && nc == c) continue;

                    visited[nr][nc] = true;
                    que.push({nr, nc});
                    reachable_count++;
                }
            }
        }
        return reachable_count < island.size() - 1;
    }

    vector<Point> get_move_candidates(int r, int c, int person) {
        vector<Point> candidates;
        auto is_island = get_reachable_map(r, c, person);

        for (int nr = 0; nr < N; nr++) {
            for (int nc = 0; nc < N; nc++) {
                bool can_reach = is_island[nr][nc];
                if (!can_reach) {
                    for (int i = 0; i < 4; i++) {
                        int pr = nr + dr[i];
                        int pc = nc + dc[i];
                        if (pr >= 0 && pr < N && pc >= 0 && pc < N && is_island[pr][pc]) {
                            can_reach = true;
                            break;
                        }
                    }
                }
                if (!can_reach) continue;

                bool occupied = false;
                for (int p = 1; p < M; p++) {
                    if (pos[p].first == nr && pos[p].second == nc) {
                        occupied = true;
                        break;
                    }
                }
                if (!occupied) candidates.push_back({nr, nc});
            }
        }
        return candidates;
    }

    long long manhattan_dist(int r, int c) {
        int top_idx = (sorted_scores[0].second == 0) ? sorted_scores[1].second : sorted_scores[0].second;
        return abs(r - pos[top_idx].first) + abs(c - pos[top_idx].second);
    }

    void prepare_turn() {
        player_islands.assign(M, vector<Point>());
        player_scores.assign(M, 0);
        sorted_scores.clear();
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int owner = O[i][j];
                if (owner != -1) {
                    player_islands[owner].push_back({i, j});
                    player_scores[owner] += V[i][j] * L[i][j];
                }
            }
        }

        for (int i = 0; i < M; i++) {
            sorted_scores.push_back({player_scores[i], i});
        }
        sort(sorted_scores.rbegin(), sorted_scores.rend());

        player_ranks.assign(M, 0);
        for (int rank = 0; rank < M; rank++) {
            int idx = sorted_scores[rank].second;
            player_ranks[idx] = rank;
        }

        // 敵の挙動を予測する
        ai_targets.assign(M, {-1, -1});
        for (int p = 1; p < M; p++) {
            double max_a = -1.0;
            Point best_target = {-1, -1};

            vector<Point> candidates = get_move_candidates(pos[p].first, pos[p].second, p);
            for (auto [r, c] : candidates) {
                double a_val = 0;

                if (O[r][c] == -1) a_val = V[r][c] * ai_params[p].wa;
                else if (O[r][c] == p) {
                    if (L[r][c] < U) a_val = V[r][c] * ai_params[p].wb;
                    else a_val = 0;
                }
                else {
                    if (L[r][c] == 1) a_val = V[r][c] * ai_params[p].wc;
                    else a_val = V[r][c] * ai_params[p].wd;
                }

                if (a_val > max_a) {
                    max_a =  a_val;
                    best_target = {r, c};
                }
            }
            ai_targets[p] = best_target;
        }

        // 一位のマスまでの距離
        auto reachable = get_reachable_map(cur_r, cur_c, 0);
        dist_to_top = 1000;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (reachable[r][c]) {
                    int d = manhattan_dist(r, c);
                    dist_to_top = min(dist_to_top, d);
                }
            }
        }

        // スコアの事前計算
        score_cache.assign(N, vector<long long> (N, 0));
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                score_cache[r][c] = evaluate(r, c, player_islands);
            }
        }
    }

    long long evaluate(int r, int c, const vector<vector<Point>>& player_islands, int turn) {
        if (L[r][c] == U) return param.LEVEL_MAX_PENALTY;

        // 初期値
        long long score = V[r][c];

        double proximity_factor = min(1.0, max(0.0, (20.0 - dist_to_top) / 10.0));
        

        // 拡張ボーナス
        if (O[r][c] == -1) score += param.EMPTY_BONUS * (1.5 - proximity_factor);

        // 角、端のボーナス
        int neighbors = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < N && nc >= 0 && nc < N) neighbors++;
        }
        if (neighbors == 2) score += param.CORNER_BONUS;
        if (neighbors == 3) score += param.EDGE_BONUS;

        // 連結保護のボーナス
        if (is_essential(r, c, 0, player_islands[0])) {
            score += param.MY_ESSENTIAL_BONUS;
        }

        for (int p = 1; p < M; p++) {
            int rank = player_ranks[p];

            // 敵の連結破壊ボーナスをランク、距離ごとに重みづけ
            if (is_essential(r, c, p, player_islands[p])) {
                long long bonus = param.ENEMY_ESSENTIAL_BONUS / (rank + 1);

                int top1_idx = (sorted_scores[0].second == 0) ? sorted_scores[1].second : sorted_scores[0].second;
                if (p == top1_idx) {
                    bonus *= (1.0 + proximity_factor * 2.0);
                }
                score += bonus;
            }

            // 衝突ペナルティをランクごとに重みづけ
            if (ai_targets[p].r == r && ai_targets[p].c == c) {
                score += param.COLLISION_PENALTY / (rank + 1);
            }
        }
        return score;
    }

    Point decide_move(int turn) {
        auto turn_start = chrono::steady_clock::now();
        vector<Node> cur_beam;
        cur_beam.push_back({cur_r, cur_c, 0, cur_r, cur_c});

        for (int d = 0; d < param.depth; d++) {
            auto now = chrono::steady_clock::now();
            double total_elapsed = chrono::duration<double>(now - start_time).count();
            double turn_elapsed = chrono::duration<double>(now - turn_start).count();

            double remaining_time = 2.0 - total_elapsed;
            double time_limit_per_turn = remaining_time / (T - turn + 1);

            if (total_elapsed > 1.90 || turn_elapsed > time_limit_per_turn * 0.90) break;

            vector<Node> next_candidates;
            for (const auto& node : cur_beam) {
                auto candidates = get_move_candidates(node.r, node.c, 0);
                for (auto [r, c] : candidates) {
                    long long ts = node.score + score_cache[r][c];
                    int fr = (d == 0) ? r : node.first_move_r;
                    int fc = (d == 0) ? c : node.first_move_c;
                    next_candidates.push_back({r, c, ts, fr, fc});
                }
            }

            if (next_candidates.empty()) break;

            sort(next_candidates.begin(), next_candidates.end(), [](const Node& a, const Node& b) {
                return a.score > b.score;
            });

            if (next_candidates.size() > (size_t)param.beam_width) {
                next_candidates.resize(param.beam_width);
            }
            cur_beam = next_candidates;
        }
        return {cur_beam[0].first_move_r, cur_beam[0].first_move_c};
    }
};

int main() {
    auto start_time = chrono::steady_clock::now();
    State st;
    st.start_time = start_time;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    st.initial();

    for (int t = 0; t < st.T; t++) {
        st.prepare_turn();
        Point next_p = st.decide_move(t);

        cout << next_p.r << " " << next_p.c << endl;

        st.update();
    }
    return 0;
}