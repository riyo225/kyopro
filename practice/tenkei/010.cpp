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
    ll n;
    cin >> n;
    vector<int> c(n);
    vector<int> p(n);
    rep(i, n) {
        cin >> c[i] >> p[i];
    }
    ll q;
    cin >> q;
    vector<ll> l(q);
    vector<ll> r(q);
    rep(i, q) {
        cin >> l[i] >> r[i];
    }
    vector<ll> csa(n+1, 0);
    vector<ll> csb(n+1, 0);
    csa[0] = 0;
    csb[0] = 0;
    rep(i, n) {
        if (c[i] == 1) {
            csa[i+1] = csa[i] + p[i];
            csb[i+1] = csb[i];
        }
        else {
            csa[i+1] = csa[i];
            csb[i+1] = csb[i] + p[i];
        }
    }

    rep(i, q) {
        cout << csa[r[i]] - csa[l[i]-1] << " " << csb[r[i]] - csb[l[i]-1] << endl;
    }

    return 0;
}