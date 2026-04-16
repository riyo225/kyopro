#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t >> n;
    
    vector<int> a(t);
    
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a[l]++;
        a[r]--;
    }

    vector<int> cs(t+1, 0);
    for (int i = 0; i < t; i++) cs[i+1] = cs[i] + a[i];

    for (int i = 1; i <= t; i++) cout << cs[i] << endl;
}