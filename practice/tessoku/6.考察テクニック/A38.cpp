#include <bits/stdc++.h>
using namespace std;

int d, n;
int l[10009], r[10009], h[10009];
int t[10009];

int main() {
    cin >> d >> n;
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i] >> h[i];

    for (int i = 1; i <= d; i++) t[i] = 24;

    for (int i = 1; i <= n; i++) {
        for (int j = l[i]; j <= r[i]; j++) t[j] = min(t[j], h[i]);
    }

    int ans = 0;
    for (int i = 1; i <= d; i++) ans += t[i];
    cout << ans << endl;
    return 0;
}