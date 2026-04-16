#include <bits/stdc++.h>
using namespace std;
#define ll long long;

long long n, sum = 0;
int a[100009];
map<int, int> m;

long long fac(long long x) {
    if (x < 2) return 0;
    return x * (x-1) / 2;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    sort(a, a + n);

    for (int i = 1; i <= n; i++) m[a[i]] += 1;

    int num = a[1];
    sum += fac(m[num]);
    for (int i = 2; i <= n; i++) {
        if (num != a[i]) {
            num = a[i];
            sum += fac(m[num]);
        }
    }
    cout << sum << endl;
    return 0;
}