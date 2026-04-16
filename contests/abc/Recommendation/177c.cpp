#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
// sortmacro
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define GT greater<int>()

// variables
int n;
int a[200009];
const ll mod = 1e9+7;
ll ss = 0;
ll ans = 0;

int main() {
    cin >> n;
    rrep(i, n) {
        cin >> a[i];
        ss = (ss + a[i]) % mod;
    }
    
    rrep(i, n) {
        ss = (ss - a[i] + mod) % mod;
        ans = ans + ((ss * a[i]) % mod) % mod;
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}