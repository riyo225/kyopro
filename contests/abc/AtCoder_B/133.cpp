#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define each(x, a) for (auto& x : a)
#define each2(a, b, c) for (auto& [a, b] : c)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) ((int)(x).size())
constexpr ll INF = (1LL << 60);
constexpr int INT_INF = (1 << 30);

int main() {
    int n, d;
    cin >> n >> d;
    vector<vector<double>> x(n, vector<double> (d));
    rep(i, n) {
        rep(j, d) {
            cin >> x[i][j];
        }
    }
    int cnt = 0;
    rep(i, n-1) {
        for (int j = i+1; j < n; j++) {
            double l = 0;
            rep(k, d) {
                l += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
            }
            l = pow(l, 0.5);
            if (l == (int)l) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}