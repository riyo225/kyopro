#include <bits/stdc++.h>
using namespace std;

const int m = 1000000007;
long long fib[10000009];

int main() {
    int n;
    cin >> n;

    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i <= n; i++) fib[i] = fib[i-1] + fib[i-2];
    
    cout << fib[n] % 1000000007 << endl;
    return 0;
}