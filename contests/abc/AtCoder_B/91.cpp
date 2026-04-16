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
    int n, m;
    cin >> n;
    map<string, int> mp;
    rep(i, n) {
        string s;
        cin >> s;
        mp[s]++;
    }
    cin >> m;
    rep(i, m) {
        string t;
        cin >> t;
        mp[t]--;
    }
    int ans = 0;
    for(auto [k, v] : mp) {
        ans = max(ans, v);
    }
    cout << ans << endl;
    return 0;
}