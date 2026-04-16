#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define Yes_No(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int main() {
    vector<string> s(3);
    rep(i, 3) cin >> s[i];
    bool ans = false;
    if (s[0][s[0].size()-1] == s[1][0] && s[1][s[1].size()-1] == s[2][0]) ans = true;
    YES_NO(ans);
    return 0;
}