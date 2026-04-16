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
const string alpha = "abcdefghijklmnopqrstuvwxyz";
const string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr ll INF = (1LL << 60);
constexpr int INT_INF = (1 << 30);

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> k(m);
    vector<vector<int>> s(m);
    rep(i, m) {
        cin >> k[i];
        s.resize(k[i]);
        rep(j, k[i]) {
            cin >> s[i][j];
        }
    }
    vector<int> p(m);
    rep(i, m) {
        cin >> p[i];
    }

    for (int b = 0; b < (1<<n); b++) {
        vector<bool> f(m, false);
        int cnt = 0;
        rep(i, n) {
            if (b & (1<<i)) {
                cnt++;
            }
        }
    }
    return 0;
}