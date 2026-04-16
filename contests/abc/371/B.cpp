#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[109];
char b[109];
bool c[109];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i] >> b[i];

    for (int i = 1; i <= n; i++) c[i] = false;

    for (int i = 1; i <= m; i++) {
        if (!c[a[i]] && b[i] == 'M') {
            cout << "Yes" << endl;
            c[a[i]] = true;
        }
        else cout << "No" << endl;
    }
}