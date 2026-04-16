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
#define nl "\n"
const string alpha = "abcdefghijklmnopqrstuvwxyz";
const string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr ll INF = (1LL << 60);
constexpr int INT_INF = (1 << 30);
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
using Graph = vector<vector<int>>;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    ll ans = INF;
    for (int i = 0; i <= max(x, y) * 2; i++) {
        if (i % 2 != 0) continue;
        ll sum = 0;
        sum += i * c;
        if (x-i/2 >= 0) sum += (x - i / 2) * a;
        if (y-i/2 >= 0) sum += (y - i / 2) * b;
        ans = min(ans, sum);
    }
    cout << ans << endl;

    return 0;
}