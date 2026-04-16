#include <bits/stdc++.h>
using namespace std;

long long power(long long a, long long b, long long m) {
    long long p = a, ans = 1;
    while(b > 0) {
        if (b % 2 == 1) {
            ans = ans * p % m;
            b--;
        }
        if (b % 2 == 0) {
            p = p * p % m;
            b = b / 2;
        }
    }
    return ans;
}

int main() {
    long long a, b;
    cin >> a >> b;
    
    cout << power(a, b, 1000000007) << endl;
    return 0;
}