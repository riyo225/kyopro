#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x; cin >> n >> x;
    vector<int> l(n);
    for (int i = 0; i < n; i++) cin >> l[i];

    vector<int> cs(n+1, 0);
    for (int i = 0; i < n; i++) {
        cs[i+1] = cs[i] + l[i];
    }

    int count = 0;
    for (int i = 0; i <= n; i++) {
        if (cs[i] <= x) {
            count++;
        }
    }

    cout << count << endl;
}