#include <bits/stdc++.h>
using namespace std;

int n;
bool isPrime[1000009];

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) isPrime[i] = true;

    // エラトステネスの篩
    for (int i = 2; i*i <= n; i++) {
        if (!isPrime[i]) continue;
        else {
            for (int j = 2; i*j <= n; j++) isPrime[i*j] = false;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (isPrime[i]) cout << i << endl;
    }
    return 0;
}