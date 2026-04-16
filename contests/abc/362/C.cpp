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
    int sum_l = 0;
    int sum_r = 0;
    rep(i, n) {
        sum_l += l[i];
        sum_r += r[i];
    }
    vi ans(n);
    int sum = 0;
    rep(i, n) {
        for (int j = l[i]; j <= r[i]; j++) {
            bool flag = false;
            if ((sum_l-l[i]+j) <= 0 && (sum_r-r[i]+j) >= 0) {
                ans[i] = j;
                sum_l = sum_l-l[i]+j;
                sum_r = sum_r-r[i]+j;
                sum += j;
                break;
            }
            
        }
    }
    if (sum == 0) {
        if (sum_l <= 0 && sum_r >= 0) {
            cout << "Yes" << endl;
            rep(i, n) cout << ans[i] << " ";
        }else {
        cout << "No" << endl;
    }
    }
}