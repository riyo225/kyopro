#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> l(q);
    vector<int> r(q);
    for (int i = 0; i < q; i++) cin >> l[i] >> r[i];

    vector<int> cs(n+1, 0);
    for (int i = 0; i < n; i++) {
        cs[i+1] = cs[i] + a[i];
    }

    for (int i = 0; i < q; i++) {
        cout << cs[r[i]] - cs[l[i]] << endl;
    }
}