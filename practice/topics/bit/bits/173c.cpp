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
const string alpha = "abcdefghijklmnopqrstuvwxyz";
const string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr ll INF = (1LL << 60);
constexpr int INT_INF = (1 << 30);

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> c(h, vector<char> (w));
    rep(i, h) {
        rep(j, w) {
            cin >> c[i][j];
        }
    }
    int ans = 0;
    repbit(b1, h) {
        repbit(b2, w) {
            vector<vector<char>> red(h, vector<char> (w, false));
            rep(i, h) {
                rep(j, w) {
                    if (b1 & (1<<i) || b2 & (1<<j)) {
                        red[i][j] = true;
                    }
                }
            }
            int cnt = 0;
            rep(i, h) {
                rep(j, w) {
                    if (!red[i][j] && c[i][j] == '#') {
                        cnt++;
                    }
                }
            }
            if (cnt == k) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}