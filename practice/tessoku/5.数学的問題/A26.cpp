#include <bits/stdc++.h>
using namespace std;

int q, x;

bool isPrime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> x;
        if (isPrime(x)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}