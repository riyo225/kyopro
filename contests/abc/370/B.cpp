#include <bits/stdc++.h>
using namespace std;

int n, a[109][109];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) cin >> a[i][j];
    }

    int ans = 1;

    for (int i = 1; i <= n; i++) {
        if (ans >= i) ans = a[ans][i];
        else ans = a[i][ans];
    }

    cout << ans << endl;
}