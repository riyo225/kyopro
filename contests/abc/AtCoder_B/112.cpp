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
constexpr int INT_INF = (1 << 30);

int main() {
    int n, T;
    cin >> n >> T;
    vector<int> c(n);
    vector<int> t(n);
    rep(i, n) cin >> c[i] >> t[i];
    int cost = INT_INF;
    rep(i, n) {
        if (t[i] <= T) {
            cost = min(cost, c[i]);
        }
    }
    if (cost == INT_INF) cout << "TLE" << endl;
    else cout << cost << endl;
    return 0;
}