#include <bits/stdc++.h>
using namespace std;

int n;
long long p[110];
bool dp[11000][110];

int main() {
    cin >> n;
    vector<int> p(n);
    int count = 0;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < 11000; i++) for (int j = 0; j < n; j++) dp[i][j] = false;
    for (int i = 0; i < n; i++) dp[0][i] = true, dp[p[0]][i] = true;

    for (int i = 0; i < 11000; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j]) {
                for (int k = j+1; k < n; k++) {
                    dp[i + p[j+1]][k] = true;
                }
            }
        }
    }
    for (int i = 0; i < 11000; i++) {
        if (dp[i][n-1]) {
            count++;
        }
    }
    cout << count << endl;
}