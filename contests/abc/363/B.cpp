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
    int n, t, p; cin >> n >> t >> p;
    vector<int> l(n);
    rep(i, n) cin >> l[i];

    vi r(n);
    rep(i, n) {
        r[i] = t - l[i];
    }
    
    sort(all(r));
    if (r[p-1] > 0) {
        cout << r[p-1];
    }
    else {
        cout << 0 << endl;
    }

}