#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define each(x, a) for (auto& x : a)
#define each2(a, b, c) for (auto& [a, b] : c)
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
    vector<vector<int>> a(3, vector<int> (3));
    rep(i, 3) {
        rep(j, 3) {
            cin >> a[i][j];
        }
    }
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i, n) {
        cin >> b[i];
    }
    vector<vector<bool>> f(3, vector<bool> (3, false));
    rep(i, n) {
        rep(s, 3) {
            rep(t, 3) {
                if (b[i] == a[s][t]) {
                    f[s][t] = true;
                }
            }
        }
    }
    bool ans = false;
    rep(i, 3) {
        if (f[i][0] && f[i][1] && f[i][2]) ans = true;
        if (f[0][i] && f[1][i] && f[2][i]) ans = true;    
    }
    if (f[0][0] && f[1][1] && f[2][2] || f[0][2] && f[1][1] && f[2][0]) ans = true;
    yes_no(ans);

    return 0;
}