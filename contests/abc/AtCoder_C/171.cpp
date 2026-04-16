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
    ll s = 26;
    ll cnt = 0;
    while (n - s > 0) {
        n -= s;
        s *= 26;
        cnt++;
    }
    cnt++;
    vector<ll> a(cnt+1);
    a[0] = 0;
    rep1(i, cnt) {
        a[i] = 1;
    }
    a[cnt] = n;
    rrep(i, cnt+1) {
        a[i-1] += a[i] / 26;
        a[i] = (a[i]+1) % 26 - 1;
    }
    if (a[cnt] == 0) {
        rep(i, cnt) cout << 'z';
    }
    else {
        rep(i, cnt+1) {
            a[i]--;
            if (a[i] == -1) continue; 
            char t = a[i] + 'a';
            cout << t;
        }
    }
    cout << endl;
    return 0;
}