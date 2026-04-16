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
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        map<char, pair<int, int>> mp;
        string a, b;
        a = s.substr(0, i);
        b = s.substr(i, n-i);
        rep(j, i) {
            mp[a[j]].first++;
        }
        rep(j, n-i) {
            mp[b[j]].second++;
        }
        int cnt = 0;
        for (auto [k, v] : mp) {
            if (v.first > 0 && v.second > 0) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}