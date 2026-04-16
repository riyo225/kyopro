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
    string s;
    cin >> s;
    vector<bool> alp(30, false);
    rep(i, s.size()) {
        alp[s[i]-'a'] = true;
    }
    rep(i, 26) {
        if (!alp[i]) {
            char c = i + 'a';
            cout << c << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}