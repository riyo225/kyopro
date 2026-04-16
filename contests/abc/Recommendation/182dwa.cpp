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
int n;
ll a[200009];
ll cs[200009];
ll csM = 0;
ll M = 0;
ll ans  = 0;

int main() {
    cin >> n;
    rrep(i, n) cin >> a[i];

    rrep(i, n) {
        cs[i] = cs[i-1] + a[i];
        M = max(M, cs[i]);
    }
    rrep(i, n) {
        cs[i] = cs[i-1] + cs[i];
        csM = max(csM, cs[i]);
    }

    ans = max(M+csM, 0LL);
    cout << ans << endl;
    return 0;
}