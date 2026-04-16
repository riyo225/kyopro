#include <iostream>
using namespace std;

int n, a[100009], b[100009];
int dp[100009];

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) cin >> a[i];
    for (int i = 3; i <= n; i++) cin >> b[i];

    dp[1] = 0;
    dp[2] = a[2];
    for (int i = 3; i <= n; i++) {
        int one = dp[i-1] + a[i];
        int two = dp[i-2] + b[i];

        dp[i] = min(one, two);
    }

    cout << dp[n] << endl;
    return 0;
}