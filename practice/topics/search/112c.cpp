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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
using Graph = vector<vector<int>>;

int main() {
    ll n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> h(n);
    rep(i, n) {
        cin >> x[i] >> y[i] >> h[i];
    }

    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            ll H = -1;
            bool flag = true;
            rep(k, n) {
                if (H != -1) {
                    if (H != h[k] + abs(x[k] - i) + abs(y[k] - j)) {
                        flag = false;
                    }
                }
                else {
                    H = h[k] + abs(x[k] - i) + abs(y[k] - j);
                }
            }
            if (flag) cout << i << " " << j << " " << H << endl;
        }
    }
    return 0;
}