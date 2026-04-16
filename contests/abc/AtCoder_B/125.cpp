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
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> c(n);
    rep(i, n) cin >> v[i];
    rep(i, n) cin >> c[i];
    rep(i, n) v[i] -= c[i];

    int ans = 0;
    rep(i, n) {
        ans = max(ans, ans+v[i]);
    }
    cout << ans << endl;
    return 0;
}