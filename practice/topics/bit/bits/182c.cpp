#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define each(x, a) for (auto& x : a)
#define each2(a, b, c) for (auto& [a, b] : c)
#define repbit(bit, n) for (int bit = 0; bit < (1<<(int)n); bit++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) ((int)(x).size())
const string alpha = "abcdefghijklmnopqrstuvwxyz";
const string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr ll INF = (1LL << 60);
constexpr int INT_INF = (1 << 30);

int main() {
    string s;
    cin >> s;
    int n = sz(s);

    int ans = INT_INF;
    repbit(b, n) {
        int sum = 0;
        int cnt = 0;
        rep(i, n) {
            if (b & (1<<i)) {
                // i番目を残す
                int a = stoi(s.substr(i, 1));
                // cout << a << endl;
                sum += a;
                cnt++;
            }
        }
        if (b != 0 && sum % 3 == 0) {
            ans = min(ans, n-cnt);
        }
    }
    if (ans == INT_INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}