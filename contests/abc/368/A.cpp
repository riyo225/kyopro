#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[109];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = k; i <= n; i++) cout << a[i] << " ";
    for (int i = 1; i <= k-1; i++) cout << a[i] << " ";
    return 0;
}