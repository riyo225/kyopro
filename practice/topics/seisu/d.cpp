#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define each(x, a) for (auto& x : a)
#define each2(a, b, c) for (auto& [a, b] : c)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) ((int)(x).size())
const string alpha = "abcdefghijklmnopqrstuvwxyz";
const string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr ll INF = (1LL << 60);
constexpr int INT_INF = (1 << 30);

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> pf;
    for (int i = 2; i * i <= n; i++) {
        int cnt = 0;
        if (n % i != 0) continue;
        while (n % i == 0) {
            cnt++;
            n /= i;
        }
        pf.push_back({i, cnt});
    }
    if (n != 1) pf.push_back({n, 1});
    
    each2(a, b, pf) {
        cout << a << " " << b << endl;
    }
    return 0;
}