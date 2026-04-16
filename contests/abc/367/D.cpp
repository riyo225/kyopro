#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200009];
int dp[200009];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    cs[1] = 0;
    for (int i = 1; i < n; i++) {
        cs[i+1] = cs[i] + a[i];
    }

    for (int s = 1; s <= n; s++) {
        for (int t = 1; t <= n; t++) {
            if (s == t) continue;
        }
    }
}