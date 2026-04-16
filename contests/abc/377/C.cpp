#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll n;
int m;
int a[200009], b[200009];
set<pair<int, int>> s;
ll ans = 0;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= m; i++) {
        s.insert(make_pair(a[i], b[i]));
        if (a[i] + 2 >= 1 && a[i] + 2 <= n && b[i] + 1 >= 1 && b[i] + 1 <= n) {
            s.insert(make_pair(a[i] + 2, b[i] + 1));
        }
        if (a[i] + 1 >= 1 && a[i] + 1 <= n && b[i] + 2 >= 1 && b[i] + 2 <= n) {
            s.insert(make_pair(a[i] + 1, b[i] + 2));
        }
        if (a[i] - 1 >= 1 && a[i] - 1 <= n && b[i] + 2 >= 1 && b[i] + 2 <= n) {
            s.insert(make_pair(a[i] - 1, b[i] + 2));
        }
        if (a[i] - 2 >= 1 && a[i] - 2 <= n && b[i] + 1 >= 1 && b[i] + 1 <= n) {
            s.insert(make_pair(a[i] - 2, b[i] + 1));
        }
        if (a[i] - 2 >= 1 && a[i] - 2 <= n && b[i] - 1 >= 1 && b[i] - 1 <= n) {
            s.insert(make_pair(a[i] - 2, b[i] - 1));
        }
        if (a[i] - 1 >= 1 && a[i] - 1 <= n && b[i] - 2 >= 1 && b[i] - 2 <= n) {
            s.insert(make_pair(a[i] - 1, b[i] - 2));
        }
        if (a[i] + 1 >= 1 && a[i] + 1 <= n && b[i] - 2 >= 1 && b[i] - 2 <= n) {
            s.insert(make_pair(a[i] + 1, b[i] - 2));
        }
        if (a[i] + 2 >= 1 && a[i] + 2 <= n && b[i] - 1 >= 1 && b[i] - 1 <= n) {
            s.insert(make_pair(a[i] + 2, b[i] - 1));
        }
    }

    ans = n * n - s.size();
    cout << ans << endl;
    return 0;
}
