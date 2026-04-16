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
    vector<char> a(3);
    vector<char> b(3);
    rep(i, 3) cin >> a[i];
    rep(i, 3) cin >> b[i];
    bool ans = true;
    rep(i, 3) {
        if (a[i] != b[3-i-1]) ans = false;
    }
    YES_NO(ans);
    return 0;
}