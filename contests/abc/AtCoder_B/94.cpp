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
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    vector<int> cs(n+1);
    cs[0] = 0;
    for (int i = 1; i <= n; i++) {
        rep(j, m) {
            if (i == a[j]) {
                cs[i] = cs[i-1] + 1;
                break;
            }
            else {
                cs[i] = cs[i-1];
            }
        }
    }
    // rep(i, n+1) cout << cs[i] << endl;
    cout << min(cs[n]-cs[x], cs[x]-cs[0]) << endl;
    return 0;
}