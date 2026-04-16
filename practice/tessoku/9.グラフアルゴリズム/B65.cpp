#include <bits/stdc++.h>
using namespace std;

int n;
int a[100009], dp[100009];
vector<int> g[100009];

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        g[a[i]].push_back(i);
    }

    for (int i = n; i >= 1; i--) {
        dp[i] = 0;
        for (int j = 0; j < g[i].size(); j++) {
            dp[i] += (dp[g[i][j]]+1);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    return 0;
}