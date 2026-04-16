#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, n;
    cin >> d >> n;
    vector<int> l(n);
    vector<int> r(n);
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

    vector<int> cs(d+1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = l[i]; j <= r[i]; j++) {
            cs[j]++;
        }
    }
    for (int i = 1; i <= d; i++) {
        cout << cs[i] << endl;
    }
}

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int d, n;
//     cin >> d >> n;
//     vector<int> a(d);
//     for (int i = 0; i < n; i++) {
//       int l, r;
//       cin >> l >> r;
//       a[l-1]++;
//       a[r]--;
//     }

//     vector<int> cs(d+1, 0);
//     for (int i = 0; i < d; i++) cs[i+1] = cs[i] + a[i];
    
//     for (int i = 1; i <= d; i++) cout << cs[i] << endl;
// }