#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[19][109];
int dp[19][1024];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= pow(2, n); j++) dp[i][j] = -1000000000;
    }

    dp[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= (1 << n); j++) {
            for (int k = 1; k <= n; k++) {
                
            }
        }
    }

    
    
    return 0;
}
