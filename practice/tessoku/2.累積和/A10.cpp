#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int d;
    cin >> d;
    vector<int> l(d);
    vector<int> r(d);
    for (int i = 0; i < d; i++) cin >> l[i] >> r[i];

    vector<int> cs_l(n);
    cs_l[0] = a[0];
    for (int i = 1; i < n; i++) {
        cs_l[i] = max(a[i], cs_l[i-1]);
    }

    vector<int> cs_r(n);
    cs_r[n-1] = a[n-1];
    for (int i = n-1; i >= 1; i--) {
        cs_r[i-1] = max(a[i-1], cs_r[i]);
    }


    for (int i = 0; i < d; i++) {
        cout << max(cs_l[l[i]-2], cs_r[r[i]]) << endl;
    }
    return 0;
}