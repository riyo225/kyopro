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
constexpr ll INF = (1LL << 60);
constexpr int INT_INF = (1 << 30);

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    int ans = INT_INF;
    for (int b = 0; b < (1<<n); b++) {
        int cnt = 0;
        vector<bool> f(m, false);
        rep(i, n) {
            if (b & (1<<i)) {
                cnt++;
                rep(j, m) {
                    if (s[i][j] == 'o') {
                        f[j] = true;
                    }
                }
            }
        }
        if (all_of(all(f), [](bool x) { return x; })) ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}