#include <bits/stdc++.h>
using namespace std;

int n, c;
int t[109];

int main() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) cin >> t[i];

    int ans = 1;
    int pos = t[1];
    for (int i = 2; i <= n; i++) {
        if (t[i]-pos >= c) {
            ans++;
            pos = t[i];
        }
    }
    cout << ans << endl;
    return 0;
}