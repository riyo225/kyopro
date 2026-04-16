#include <iostream>
using namespace std;

int n, x, a[100009];

int search(int x) {
    int pos = lower_bound(a + 1, a + n + 1, x) - a;
    if (pos <= n && a[pos] == x) return pos;
    return -1;
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = search(x);
    cout << ans << endl;
    return 0;
}