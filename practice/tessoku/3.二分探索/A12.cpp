#include <iostream>
using namespace std;

int n, k, a[100009];

bool check(long long m) {
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += m / a[i];
    if (sum >= k) return true;
    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    long long l = 1, r = 1000000000;
    while (l < r) {
        long long m = (l + r) / 2;
        bool ans = check(m);
        if (ans) r = m;
        else l = m + 1;
    }

    if (l == r) cout << l << endl;
    return 0;
    
}