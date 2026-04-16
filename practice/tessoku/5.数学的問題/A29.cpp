#include <bits/stdc++.h>
using namespace std;

long long power(long long a, long long b, long long m) {
    long long p = a, ans = 1;
    for (int i = 0; i < 30; i++) {
        int wari = (1 << i);
        if ((b / wari) % 2 == 1) {
            ans = (ans * p) % m;
        }
        p = p * p % m;
    }
    return ans;
}

int main() {
    long long a, b;
    cin >> a >> b;
    
    cout << power(a, b, 1000000007) << endl;
    return 0;
}