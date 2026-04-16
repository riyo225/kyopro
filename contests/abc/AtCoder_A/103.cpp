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
    vector<int> a(3);
    rep(i, 3) cin >> a[i];
    vector<int> b(3);
    b[0] = abs(a[0] - a[1]);
    b[1] = abs(a[1] - a[2]);
    b[2] = abs(a[2] - a[0]);
    sort(all(b));
    cout << b[0] + b[1] << endl;
    return 0;
}