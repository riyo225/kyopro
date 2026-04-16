#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int b; cin >> b;
    int res = -1;
    for (int i = 0; i < b; i++) {
        if (pow(i, i) == b) {
            res = i;
            break;
        }
    }
    cout << res << endl;
}