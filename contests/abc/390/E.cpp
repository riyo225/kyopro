#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
// sortmacro
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define GT greater<int>()
// priority_queue
#define VG vector<int>, greater<int>

// variables
int n, x;
int v[5009];
int a[5009];
int c[5009];
ll dpf[5009][5009];
ll dps[5009][5009];
ll dpt[5009][5009];

int main() {
    cin >> n >> x;
    rrep(i, n) {
        cin >> v[i] >> a[i] >> c[i];
    }

    dpf[0][0] = 0;
    dps[0][0] = 0;
    dpt[0][0] = 0;
    rrep(i, n) {
        for (int j = 0; j <= x; j++) {
            if (v[i] == 1) {
                dpf[i][j] = max(dpf[i-1][j], dpf[i-1][j-c[i]]+a[i]);
            }
            else {
                dpf[i][j] = max(dpf[i-1][j], dpf[i-1][j-c[i]]);
            }
            if (v[i] == 2) {
                dps[i][j] = max(dps[i-1][j], dps[i-1][j-c[i]]+a[i]);
            }
            else {
                dps[i][j] = max(dps[i-1][j], dps[i-1][j-c[i]]);
            }
            if (v[i] == 3) {
                dpt[i][j] = max(dpt[i-1][j], dpt[i-1][j-c[i]]+a[i]);
            }
            else {
                dpt[i][j] = max(dpt[i-1][j], dpt[i-1][j-c[i]]+a[i]);
            }
        }
    }

    ll aa, bb, cc;

    for(int i = 0;i <= x; i++) {
        aa = min(dpf[n][i], aa);
        bb = (dps[n][i], bb);
        cc = max(dpt[n][i], cc);
    }

    ll ans = min(aa, bb);
    ans = min(ans, cc);

    cout << ans << endl;

    return 0;
}