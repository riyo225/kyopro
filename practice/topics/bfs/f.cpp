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

    int sh, sw, gh, gw;
    rep(i, H) {
        rep(j, W) {
            if (field[i][j] == 'S') {
                sh = i;
                sw = j;
            }
            if (field[i][j] == 'G') {
                gh = i;
                gw = j;
            }
        }
    }

    queue<pair<int, int>> que;
    vector<vector<int>> dist(H, vector<int> (W, -1));

    que.push({sh, sw});
    dist[sh][sw] = 0;

    while (!que.empty()) {
        int vh = que.front().first;
        int vw = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nvh = vh + dx[i];
            int nvw = vw + dy[i];

            if (nvh < 0 || nvh >= H || nvw < 0 || nvw >= W) continue;
            if (field[nvh][nvw] == '#') continue;
            if (dist[nvh][nvw] != -1) continue;

            dist[nvh][nvw] = dist[vh][vw] + 1;
            que.push({nvh, nvw});
        }
    }

    yes_no(dist[gh][gw] != -1);

    return 0;
}