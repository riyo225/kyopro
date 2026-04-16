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

int main() {
    int n, m, xx, yy;
    cin >> n >> m >> xx >> yy;
    vector<int> x(n);
    vector<int> y(m);
    rep(i, n) cin >> x[i];
    rep(i, m) cin >> y[i];
    sort(all(x));
    sort(all(y));
    bool ans = false;
    for (int i = xx+1; i <= yy; i++) {
        if (x[n-1] < i && i <= y[0]) {
            ans = true;
            break;
        }
    }
    if (ans) cout << "No War" << endl;
    else cout << "War" << endl;
}