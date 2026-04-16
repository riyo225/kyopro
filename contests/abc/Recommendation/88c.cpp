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
ll x, y;
int ans = 0;

int main() {
    cin >> x >> y;

    while (x <= y) {
        ++ans;
        x *= 2;
    }

    cout << ans << endl;

    return 0;
}