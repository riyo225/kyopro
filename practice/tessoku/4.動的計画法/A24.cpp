// #include <bits/stdc++.h>
// using namespace std;

// int n;
// int a[100009], dp[100009];

// int main() {
//     cin >> n;
//     for (int i = 1; i <= n; i++) cin >> a[i];

//     for (int i = 1; i <= n; i++) {
//         dp[i] = 1;
//         for (int j = 1; j < i; j++) {
//             if (a[j] < a[i]) dp[i] = max(dp[j] + 1, dp[i]);
//         }
//     }

//     cout << dp[n] << endl;
//     return 0;    
// }

#include <bits/stdc++.h>
using namespace std;

int n;
int a[100009], dp[100009];
int len = 0;
int l[100009];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(l + 1, l + len + 1, a[i]) - l;
        dp[i] = pos;
        cout << " " << len << " " << a[i] << " " << pos << endl;

        l[dp[i]] = a[i];
        if (dp[i] > len) len++;
    }

    cout << len << endl;
}