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
    vector<int> a(5);
    rep(i, 5) cin >> a[i];
    vector<int> b(5);
    rep(i, 5) {
        if (a[i] % 10 == 0) b[i] = a[i];
        else b[i] = (a[i] / 10 + 1) * 10;
    }
    ll ans = INF;
    rep(i, 5) {
        rep(j, 5) {
            
        }
    }

    return 0;
}