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
double n, m;
const double l = 6.0;
const double s = 0.5;
double ans = 0;

int main() {
    cin >> n >> m;
    double L, S;

    if (n >= 12) n -= 12;
    S = l * 5 * n + m * s;
    L = l * m;

    S = fmod(S, 360);
    L = fmod(L, 360);
    ans = min(abs(S-L), 360-abs(S-L));

    cout << ans << endl;
    return 0;
}