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
    string t, u;
    cin >> t >> u;
    bool ans = false;
    for (int i = 0; i <= t.size() - u.size(); i++) {
        string v = t.substr(i, u.size());
        // cout << v << endl;
        // cout << "------" << endl;
        bool a = true;
        rep(j, u.size()) {
            // cout << v[j] << " " << u[j] << endl;
            if (v[j] != '?' && v[j] != u[j]) {
                a = false;
            }
        }
        if (a) ans = true;
    }
    yes_no(ans);
    return 0;
}