#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int n, m;
ll b[200009], w[200009];
ll csb[200009];
ll csw[200009];
ll cs[200009];

int main() {
    cin >> n >> m;
    rrep(i, n) cin >> b[i];
    rrep(i, m) cin >> w[i];

    sort(b+1, b+n+1, greater<int>());
    sort(w+1, w+m+1, greater<int>());

    int idx = -1;
    for (int i = 1; i <= n; i++) {
        if (b[i] < 0) {
            idx = i;
            break;
        }
    }
    
    for (int i = 0; i <= n; i++) {
        csb[i] = 0;
    }
    for (int i = 0; i <= m; i++) {
        csw[i] = 0;
    }

    csb[0] = 0;
    rrep(i, n) {
        csb[i] = csb[i-1] + b[i];
    }

    csw[0] = 0;
    rrep(i, m) {
        csw[i] = csw[i-1] + w[i];
    }
    
    cs[0] = 0;
    rrep(i, max(m, n)) {
        cs[i] = csb[i] + csw[i];
    }
    
    ll ans = 0;
    for (int i = 0; i <= min(m, n); i++) {
        if (idx != -1) {
            if (idx < i) {
                ans = max(ans, cs[i]);
            }
            else {
                ans = max(ans, cs[i] + csb[idx] - csb[i]);
            }
        }
        else {
            ans = max(ans, cs[i]);
        }
    }
    for (int i = 0; i <= n; i++) {
        cout << cs[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i <= n; i++) {
        cout << csb[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i <= m; i++) {
        cout << csw[i] << " ";
    }
    cout << ans << endl;
    return 0;
}