#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<int, int> p;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        p[a] = i;
    }
    int q; cin >> q;
    vector<int> a(q);
    vector<int> b(q);
    for (int i = 0; i < q; i++) cin >> a[i] >> b[i];

    for (int i = 0; i < q; i++) {
        if (p[a[i]] > p[b[i]]) {
            cout << b[i] << endl;
        }
        else {
            cout << a[i] << endl;
        }
    } 
}