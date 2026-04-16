#include <bits/stdc++.h>
using namespace std;

int n;
int a[109], b[109];
int sum = 0;
int ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        sum += b[i];
    }
    if (sum%3 == 0) {

    }
    else {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}