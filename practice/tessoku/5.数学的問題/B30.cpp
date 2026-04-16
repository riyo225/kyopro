#include <bits/stdc++.h>
using namespace std;

const int m = 1000000007;
int h, w;

long long fanc(int x) {
    long long res = 1;
    while (x > 0) {
        res = res * x % m;
        x--;
    }
    return res;
}

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
    cin >> h >> w;

    long long a = fanc(h + w - 2);
    long long b = fanc(w - 1);
    long long c = fanc(h - 1);

    long long d = b * c % m;
    d = power(d, m-2, m);

    cout << a * d % m << endl;
    return 0;
}