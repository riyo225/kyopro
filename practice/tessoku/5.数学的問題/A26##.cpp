#include <bits/stdc++.h>
using namespace std;

int q, n = 300000;
int x[300009];
bool isPrime[300009];

int main() {
    cin >> q;
    for (int i = 1; i <= q; i++) cin >> x[i];
    for (int i = 2; i <= n; i++) isPrime[i] = true;

    for (int i = 2; i*i <= n; i++) {
        if (!isPrime[i]) continue;
        else {
            for (int j = 2; i*j <= n; j++) isPrime[i*j] = false;
        }
    }

    for (int i = 1; i <= q; i++) {
        if (isPrime[x[i]]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}