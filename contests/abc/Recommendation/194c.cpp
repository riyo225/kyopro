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

// variables
int n;
int a[300009];
ll ss = 0, s = 0, t = 0, ans = 0;

int main() {
    cin >> n;
    rrep(i, n) {
        cin >> a[i];
        ss += a[i];
    }

    rrep(i, n) {
        s += a[i] * a[i];
    }

    rrep(i, n) {
        ss -= a[i];
        t += a[i] * ss;
    }

    cout << s * (n-1) - t * 2 << endl;

    return 0;
}