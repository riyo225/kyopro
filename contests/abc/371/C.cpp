#include <bits/stdc++.h>
using namespace std;

#define INF (int)2e+9

int n, s, ans = INF, ss = 0;
int k[29];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        ss += k[i];
    }

    for (int i = 0; i < (1 << n); i++) {
        s = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) s += k[j];
        }
        ans = min(ans, max(s, ss-s));
    }
    cout << ans << endl;
    return 0;
}