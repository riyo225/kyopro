#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n; cin >> n;
    bool flag = false;
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 30; j++) {
            if (pow(2, i) * pow(3, j) == n) {
                flag = true;
            } 
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}