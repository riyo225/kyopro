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
    int w, h, n;
    cin >> w >> h >> n;
    vector<int> x(n);
    vector<int> y(n);
    vector<int> a(n);
    rep(i, n) cin >> x[i] >> y[i] >> a[i];

    int ml = 0, mr = w, mu = h, md = 0;
    rep(i, n) {
        if (a[i] == 1) {
            ml = max(ml, x[i]);
        }
        if (a[i] == 2) {
            mr = min(mr, x[i]);
        }
        if (a[i] == 3) {
            md = max(md, y[i]);
        }
        if (a[i] == 4) {
            mu = min(mu, y[i]);
        }
    }
    if (mr-ml > 0 && mu-md > 0) cout << (mr-ml)*(mu-md) << endl;
    else cout << 0 << endl;
    return 0;
}