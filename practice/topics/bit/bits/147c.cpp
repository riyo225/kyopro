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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<pair<int, int>>> vec(n);
    rep(i, n) {
        cin >> a[i];
        vec[i].resize(a[i]);
        rep(j, a[i]) {
            cin >> vec[i][j].first >> vec[i][j].second;
            vec[i][j].first--;
        }
    }
    
    int ans = 0;
    repbit(b, n) {
        vector<bool> f(n, false);
        // 矛盾があるか
        bool flag = true;
        rep(i, n) {
            if (b & (1<<i)) {
                f[i] = true;
                // 各証言について
                rep(j, a[i]) {
                    int fst = vec[i][j].first;
                    int snd = vec[i][j].second;
                    if (snd == 1 && !(b & (1<<fst))) {
                        flag = false;
                    }
                    if (snd == 0 && (b & (1<<fst))) {
                        flag = false;
                    }
                }
                
            }
        }
        int cnt = 0;
        if (flag) {    
            rep(i, n) {
                if (f[i]) cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}