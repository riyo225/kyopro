#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "yes" : "no") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int main() {
    string s;
    cin >> s;
    map<int, char> mp;
    rep(i, s.size()) {
        mp[s[i]]++;
    }
    bool ans = true;
    for (auto [k, v] : mp) {
        if (v != 1) ans = false;
    }
    yes_no(ans);
    return 0;
}