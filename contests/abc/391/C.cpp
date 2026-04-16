#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int main() {
    ll n, q;
    cin >> n >> q;
    vector<int> a(n);
    map<int, int> mp;
    ll ans = 0;

    rep(i, n) {
        a[i] = i;
        mp[i] = 1;
    }

    rep(i, q) {
        int one;
        cin >> one;
        if (one == 1) {
            int p, h;
            cin >> p >> h;
            p--;
            h--;
            mp[a[p]]--;
            if (mp[a[p]] == 1) ans--;
            mp[h]++;
            if (mp[h] == 2) ans++;
            a[p] = h;
        }
        else {
            cout << ans << endl;
        }
    }

    return 0;
}