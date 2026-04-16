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
    int n; cin >> n;
    vi l(n); vi r(n);
    rep(i, n) cin >> l[i] >> r[i];
    vi sum_l(n+1,0); vi sum_r(n+1,0);
    rep(i, n) {
        sum_l[i+1] = sum_l[i] + l[i];
        sum_r[i+1] = sum_r[i] + r[i];
    }
    vi ans(n);
    int sum = 0;
    rep(i, n) {
        if ((l[i]+sum) <= 0 && (sum+r[i]) >= 0) {
            ans[i] = -sum;
            cout << l[i]+sum << ":" << sum+r[i] << endl;
            cout << sum << endl;
        }
        else {
            if ((l[i]+sum) > 0) {
                cout << l[i]+sum << ":" << sum+r[i] << endl;
                ans[i] = l[i];
                sum += l[i];
               
                cout << sum << endl;
            }
            else {
                ans[i] = r[i];
                cout << l[i]+sum << ":" << sum+r[i] << endl;
                sum += r[i];
                
                cout << sum << endl;
            }
        }
    }
    if (sum == 0) {
        cout << "Yes" << endl;
        rep(i, n) cout << ans[i] << " ";
    }
    else {
        cout << "No" << endl;
    }
    rep(i, n) cout << ans[i] << " ";
    cout << endl;
    cout << sum << endl;
}