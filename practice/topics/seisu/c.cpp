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
    vector<ll> div;
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (n / i == i) {
                 div.push_back(n/i);
            }
        }
    }
    ll s = div.size();
    ll m = div[s-1];
    int cnt = 0;
    while (m) {
        m /= 10;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}