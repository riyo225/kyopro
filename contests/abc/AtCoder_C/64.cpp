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
constexpr ll INF = (1LL << 60);
constexpr int INT_INF = (1 << 30);

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    set<ll> st;
    ll t = 0;
    rep(i, n) {
        int cnt = 0;
        while (a[i] >= 0) {
            a[i] -= 400;
            cnt++;
        }
        if (cnt >= 9) t++;
        else st.insert(cnt);
    }
    // each(x, st) {
    //     cout << x << endl;
    // }
    cout << max((ll)1, (ll)st.size()) << " " << st.size() + t << endl;
    return 0;
}