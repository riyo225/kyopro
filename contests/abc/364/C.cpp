#include <bits/stdc++.h>
using namespace std;

int n, x, y;
int a[200009], b[200009];
vector<pair<int, int>> c;
long long sa=numeric_limits<long long>::max(), sb=numeric_limits<long long>::max();
int csa[200009], csb[200009];

int main() {
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sa+=a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        sb+=b[i];
    }

    sort(a+1, a+n+1, greater<int>());
    sort(b+1, b+n+1, greater<int>());

    csa[0] = 0, csb[0] = 0;
    for (int i = 0; i <= n-1; i++) {
        csa[i+1] = csa[i] + a[i];
        csb[i+1] = csb[i] + a[i];
    }

    if (sa >= x) {
        long long sa = lower_bound(a+1, a+n+1, x)-a;
    }
    if (sb >= y) {
        long long sb = lower_bound(b+1, b+n+1, x)-b;
    }

    cout << max(sa, sb) << endl;
    return 0;
}