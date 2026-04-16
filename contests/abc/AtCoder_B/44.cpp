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
    string w;
    cin >> w;
    map<char, int> mp;
    rep(i, w.size()) {
        mp[w[i]]++;
    }
    bool ans = true;
    for (auto [k, v] : mp) {
        if (v % 2 != 0) ans = false;
    }
    yes_no(ans);
    return 0;
}