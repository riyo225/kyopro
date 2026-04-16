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
    int n;
    cin >> n;
    vector<double> x(n);
    vector<double> y(n);
    rep(i, n) cin >> x[i] >> y[i];
    map<pair<double, double>, int> mp;
    map<int, int> mpx;
    rep(i, n-1) {
        double sx, sy;
        for (int j = i+1; j < n; j++) {
            sx = x[j] - x[i];
            sy = y[j] - y[i];
            if (sx == 0) {
                mpx[x[i]]++;
            }
            else {
                mp[{sy/sx, y[i]-sy/sx*x[i]}]++;
            }
        }
    }
    bool ans = false;
    each2 (k, v, mp) {
        if (v >= 2) {
            ans = true;
        }
    }
    each2 (k, v, mpx) {
        if (v >= 2) {
            ans = true;
        }
    }
    yes_no(ans);
    return 0;
}