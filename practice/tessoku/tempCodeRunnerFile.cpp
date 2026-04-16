#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (x >= a[n/2]) {
        for (int i = n/2; i < n; i++) {
            if (a[i] == x) cout << i+1 << endl;
        }
    }
    else {
        for (int i = 0; i <= n/2; i++) {
            if (a[i] == x) cout << i+1 << endl;
        }
    }
}