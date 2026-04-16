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
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int> (m));
    rep(i, n) {
        cin >> c[i];
        rep(j, m) {
            cin >> a[i][j];
        }
    }
    
    ll ans = INF;
    repbit(b, n) {
        ll sum = 0;
        vector<ll> vec(m, 0);
        rep(i, n) {
            if (b & (1<<i)) {
                // 本iを購入する
                sum += c[i];
                rep(j, m) {
                    vec[j] += a[i][j];
                }
            }
        } 
        
        // すべてがx以上か判定
        bool flag = true;
        rep(i, m) {
            if (vec[i] < x) {
                flag = false;
            }
        }
        if (flag) ans = min(ans, sum);
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}