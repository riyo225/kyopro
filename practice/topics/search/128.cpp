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
struct Edge
{
    int to;
    ll cost;
};
using Graph = vector<vector<int>>;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> k(m);
    vector<vector<int>> s(m);
    vector<int> p(m);
    rep(i, m) {
        cin >> k[i];
        s[i].resize(k[i]);
        rep(j, k[i]) {
            cin >> s[i][j];
        }
    }
    rep(i, m) {
        cin >> p[i];
    }
    int ans = 0;
    repbit(b, n) {
        vector<bool> f(m, false);
        rep(i, m) {
            int cnt = 0;
            rep(j, k[i]) {
                if (b & (1<<(s[i][j]-1))) {
                    cnt++;
                }
            }
            if (cnt % 2 == p[i]) {
                f[i] = true;
            }
        }
        bool flag = true;
        rep(i, m) {
            if (!f[i]) {
                flag = false;
                break;
            }
        }
        if (flag) ans++;
    }
    cout << ans << endl;
    return 0;
}