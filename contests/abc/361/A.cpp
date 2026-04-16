#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

signed main() {
    int n, k, x; cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
        if (i+1 == k) {
            cout << x << " ";
        }
    }
}