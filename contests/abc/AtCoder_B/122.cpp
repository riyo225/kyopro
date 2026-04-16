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
    string s;
    cin >> s;
    int n = sz(s);
    vector<bool> f(n, false);
    rep(i, n) {
        if (s[i] == 'A' || s[i] == 'G' || s[i] == 'C' || s[i] == 'T') {
            f[i] = true;
        }
    }
    int ans = 0;
    rep(i, n) {
        int cnt = 0;
        while (f[i] && i < n) {
            cnt++;
            i++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}