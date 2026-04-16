#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define each(x, a) for (auto& x : a)
#define each2(a, b, c) for (auto& [a, b] : c)
#define repbit(bit, n) for (int bit = 0; bit < (1<<(int)n); bit++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) ((int)(x).size())
#define nl "\n"
const string alpha = "abcdefghijklmnopqrstuvwxyz";
const string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr ll INF = (1LL << 60);
constexpr int INT_INF = (1 << 30);
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> field(H);
    rep(i, H) {
        cin >> field[i];
    }

    vector<vector<int>> dist(H, vector<int> (W, INT_INF));
    queue<pair<int, int>> que;

    vector<vector<char>> ans(H, vector<char> (W));

    vector<pair<int, int>> Exit;
    rep(i, H) {
        rep(j, W) {
            if (field[i][j] == 'E') {
                Exit.push_back({i, j});
                ans[i][j] = 'E';
            }
            if (field[i][j] == '#') ans[i][j] = '#';
        }
    }

    for (int i = 0; i < Exit.size(); i++) {
        int eh = Exit[i].first;
        int ew = Exit[i].second;
        que.push(Exit[i]);
        dist[eh][ew] = 0;
    }

    while(!que.empty()) {
        int vh = que.front().first;
        int vw = que.front().second;
        que.pop();

        rep(j, 4) {
            int nvh = vh + dx[j];
            int nvw = vw + dy[j];

            if (nvh < 0 || nvh >= H || nvw < 0 || nvw >= W) continue;
            if (field[nvh][nvw] == '#') continue;
            if (dist[vh][vw]+1 >= dist[nvh][nvw]) continue;
            
            dist[nvh][nvw] = min(dist[nvh][nvw], dist[vh][vw] + 1);
            que.push({nvh, nvw});

            if (field[nvh][nvw] == 'E') continue;
            if (j == 0) ans[nvh][nvw] = '^';
            if (j == 1) ans[nvh][nvw] = '<';
            if (j == 2) ans[nvh][nvw] = 'v';
            if (j == 3) ans[nvh][nvw] = '>';

        }
    }

    rep(i, H) {
        rep(j, W) {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}