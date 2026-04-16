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
    ll n;
    cin >> n;
    ll sum = 0;
    ll m = n;
    while (n != 0) {
        sum += (n % 10);
        n /= 10;
    }
    bool ans = false;
    if (m % sum == 0) ans = true;
    yes_no(ans);
    return 0;
}