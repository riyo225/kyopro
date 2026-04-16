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
    ll n, m, q;
    cin >> n >> m >> q;
    vector<bool> al(n);
    vector<unordered_set<ll>> pa(n);
    rep(i, n) al[i] = false;
    while (q > 0) {
        int a;
        cin >> a;
        if (a == 1) {
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            pa[x].insert(y);
        }
        else if (a == 2) {
            ll x;
            cin >> x;
            x--;
            al[x] = true;
        }
        else {
            ll x, y;
            cin >> x >> y;
            x--;
            y--;
            bool ans = false;
            if (al[x]) {
                ans = true;
            }
            else {
                ans = (pa[x].find(y) != pa[x].end());
            }
            yes_no(ans);
        }
        q--;
    }

    return 0;
}