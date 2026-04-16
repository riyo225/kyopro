#include <bits/stdc++.h>
using namespace std;

int n;
int a[500009], b[500009];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    cout << a[n] + b[n] << endl;
    return 0;
}