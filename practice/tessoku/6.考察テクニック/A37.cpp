#include <bits/stdc++.h>
using namespace std;

long long n, m, b;
long long a[200009], c[200009];

int main() {
    cin >> n >> m >> b;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> c[i];

    long long ans = 0;
    for (int i = 1; i <= n; i++) ans += a[i] * m;
    for (int i = 1; i <= m; i++) ans += c[i] * n;
    ans += b * n * m;

    cout << ans << endl;
    return 0;
}