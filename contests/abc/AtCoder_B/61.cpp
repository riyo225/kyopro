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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);
    rep(i, m) cin >> a[i] >> b[i];
    vector<int> c(n, 0);
    rep(i, m) {
        c[a[i]-1]++;
        c[b[i]-1]++;
    }
    rep(i, n) cout << c[i] << endl;

    return 0;
}