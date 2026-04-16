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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
    }
    int k;
    cin >> k;
    vector<int> c(k);
    vector<int> d(k);
    rep(i, k) {
        cin >> c[i] >> d[i];
    }

    int ans = 0;
    repbit(bit, k) {
        vector<bool> ball(n, false);
        rep(i, k) {
            if (bit & (1<<i)) {
                // 配列dから選ぶ
                ball[d[i]] = true;
            }
            else {
                ball[c[i]] = true;
            }
        }
        int cnt = 0;
        rep(i, m) {
            if (ball[a[i]] && ball[b[i]]) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}