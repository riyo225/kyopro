#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n, 1);
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        a[t-1]^= 1;
    }
}