#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

signed main() {
    int a, b, c, d, e, f, g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;

    bool x=false, y=false, z=false;
    if (d > g && j > a) {
        x = true;
    }
    if (e > h && k > b) y = true;
    if (f > i && l > c) z = true;

    if (x && y) {
        if (x && z) {
            cout << "Yes" << endl;
        }
    }
    else {
        cout << "No" << endl;
    }
}