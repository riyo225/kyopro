// [prefix: gridbfs]

const ll dr[] = {1, 0, -1, 0}; const ll dc[] = {0, 1, 0, -1};
string DIRS = "DRUL";
const ll dr8[] = {1, 1, 0, -1, -1, -1, 0, 1}; const ll dc8[] = {0, 1, 1, 1, 0, -1, -1, -1};
auto is_inside = [&](ll r, ll c) { return 0 <= r && r < h && 0 <= c && c < w; };
auto is_outside = [&](ll r, ll c) { return r < 0 || h <= r || c < 0 || w <= c; };
auto get_id = [&](ll r, ll c) { return r * w + c; };
auto get_2d = [&](ll id)  { return make_pair(id / w, id % w); };

vector<vector<ll>> dist(h, vector<ll> (w, -1));
vector<vector<ll>> from(h, vector<ll> (w, -1));
queue<pll> que; 

while (!que.empty()) {
    auto [r, c] = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
        ll nr = r + dr[i];
        ll nc = c + dc[i];
        if (is_outside(nr, nc)) continue;
        if (vec[nr][nc] == '#' || dist[nr][nc] != -1) continue;
        dist[nr][nc] = dist[r][c] + 1;
        from[nr][nc] = i;
        que.push({nr, nc});
    }
}