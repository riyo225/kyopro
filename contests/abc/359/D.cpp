#include <bits/stdc++.h>
using namespace std;
#define int long long
 
signed main() {
    int n; cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            if (h[i-1] >= h[i]) {
                res[i] = res[i-1] + h[i];
            }
            else {
                res[i] = (i+1) * h[i] + 1;
            }
        }
        else {
            res[i] = h[i] + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i];
        if (i != n-1) {
            cout << " ";
        }
    }
}