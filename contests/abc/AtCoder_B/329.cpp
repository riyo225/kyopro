#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end(), greater<int>());
    int max = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] == max) {
            a[i] = 0;
        }
    }
    sort(a.begin(), a.end(), greater<int>());
    cout << a[0] << endl;
}