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
int r[109], q[109];
int Q;
int t[109], d[109];

int main() {
    cin >> n;
    rrep(i, n) cin >> q[i] >> r[i];
    cin >> Q;
    rrep(i, Q) cin >> t[i] >> d[i];

    rrep(i, Q) {
        int pos = d[i] % q[t[i]];
        int p = d[i] / q[t[i]];
        if (pos <= r[t[i]]) {
            cout << q[t[i]] * p + r[t[i]] << endl;
        }
        else {
            p++;
            cout << q[t[i]] * p + r[t[i]] << endl;
        }
    }
    return 0;
}