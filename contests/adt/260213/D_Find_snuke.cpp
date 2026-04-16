#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

const int dh[4] = {1, 0, -1, 0};
const int dw[4] = {0, 1, 0, -1};

int H, W;
vector<string> field;

bool seen[510][510];
void dfs(int h, int w) {
    seen[h][w] = true;

    for (int i = 0; i < 4; i++) {
        int nh = h + dh[i];
        int nw = w + dw[i];

        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
        if (field[nh][nw] == '#') continue;

        if (seen[nh][nw]) continue;
        dfs(nh, nw);
    }
    // 単純パス
    // seen[x][y] = false;
}

int main() {
    // 行と列
    cin >> H >> W;
    field.resize(H);
    for (int i = 0; i < H; i++) cin >> field[i];

    int sh, sw, gh, gw;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
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

    memset(seen, 0, sizeof(seen));
    dfs(sh, sw);

    if (seen[gh][gw]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}