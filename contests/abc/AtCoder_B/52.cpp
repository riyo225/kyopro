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
    int x = 0;
    int ans = 0;
    rep(i, n) {
        if (s[i] == 'I') x++;
        else if (s[i] == 'D') x--;
        ans = max(ans, x);
    }
    cout << ans << endl;
    return 0;
}