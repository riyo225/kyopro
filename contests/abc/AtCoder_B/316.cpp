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
    int m; cin >> m;
    vi d(m);
    rep(i, m) cin >> d[i];

    int count = 0;
    rep(i, m) {
        count += d[i];
    }

    int date = (count+1) / 2;

    rep(i, m) {
        if (date > d[i]) {
            date -= d[i];
        }
        else {
            cout << i+1 << " " << date << endl;
            break;
        }

    }
}