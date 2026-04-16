#include <iostream>
#include <algorithm>
using namespace std;

int n, k, a[1009], b[1009], c[1009], d[1009], p[1000009], q[1000009];

bool search(int x) {
    int pos = lower_bound(q + 1, q + n * n + 1, x) - q;
    if (pos <= n * n && q[pos] == x) return true;
    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> d[i];

    int index = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) p[index++] = a[i] + b[j];
    }

    index = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) q[index++] = c[i] + d[j];
    }

    for (int i = 1; i <= n * n; i++) p[i] = k - p[i];

    sort(q + 1, q + n * n + 1);
    
    bool flag = false;
    for (int i = 1; i <= n * n; i++) {
        bool ans = search(p[i]);
        if (ans) {
            cout << "Yes" << endl;
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << "No" << endl;
    }
    return 0;
}