#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<string> b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    bool ans = false;

    rep(i, n-m+1) {
        rep(j, n-m+1) {
            bool flag = true;
            rep(c, m) {
                rep(d, m) {
                    if (a[i+c][j+d] != b[c][d]) {
                        flag = false;
                    }
                }
            }
            if (flag) {
                ans = true;
            }
        }
    }

    yes_no(ans);

    return 0;
}