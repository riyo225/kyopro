#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Yes(b) ((b)?"Yes":"No")
#define YES(b) ((b)?"YES":"NO")
using vi = vector<int>;

signed main() {
    int n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    vi b(n);
    rep(i, n) b[i] = a[i];

    sort(all(b));

    rep(i, n) {
        if (b[n-2] == a[i]) {
            cout << i+1 << endl;
        }
    }

}