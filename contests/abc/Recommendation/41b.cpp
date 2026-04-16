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
ll a, b, c, ans = 1;
const ll mod = 1e9+7;

int main() {
    cin >> a >> b >> c;
    ans *= a;
    ans *= b;
    ans %= mod;
    ans *= c;
    ans %= mod;
    cout << ans << endl;
    return 0;
}