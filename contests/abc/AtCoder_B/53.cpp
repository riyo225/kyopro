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
    ll n = s.size();
    ll l, r;
    rep(i, n) {
        if (s[i] == 'A') {
            l = i;
            break;
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == 'Z') {
            r = i;
            break;
        }
    }
    cout << r - l + 1 << endl;
    return 0;
}