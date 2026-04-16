#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100009], q, x;

int search(int x) {
    int pos = lower_bound(a + 1, a + n + 1, x) - a;
    if (pos <= n && a[pos] == x) return pos - 1;
    if (pos <= n && a[pos] > x) return pos;
    return -1;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;

    sort(a + 1, a + n + 1);

    for (int i = 0; i < q; i++) {
        cin >> x;
        int ans = search(x);
        cout << ans << endl;
    }
    return 0;
}