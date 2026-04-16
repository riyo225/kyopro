#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Yes(b) ((b)?"Yes":"No")
#define YES(b) ((b)?"YES":"NO")
using vi = vector<int>;

signed main() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];
    int sum = 0;
    rep(i, n) sum += a[i];
    int max_x = m / n;
    sort(all(a));
    vi s(n+1, 0);
    rep(i, n) {
        s[i+1] = s[i] + a[i];
    }
    int max_xx = 0;
    if (sum <= m) cout << "infinite" << endl;
    else {
        rep(i, n+1) {
            if (s[i] < m) {
                int ss = (m-s[i])/n;
                max_xx = max(max_xx, ss);
            }
        }
        cout << max_x << endl;
    }

}