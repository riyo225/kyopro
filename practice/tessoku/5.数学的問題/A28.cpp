#include <bits/stdc++.h>
using namespace std;

int n;
long long ans = 0;
char t[100009];
int a[100009];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t[i] >> a[i];

    for (int i = 1; i <= n; i++) {
        if (t[i] == '+') ans += a[i];
        else if (t[i] == '-') ans -= a[i];
        else ans *= a[i];

        if (ans < 0) ans += 10000;
        ans %= 10000;
        cout << ans << endl;
    }
    return 0;
}