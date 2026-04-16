#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
// sortmacro
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define GT greater<int>()
// priority_queue
#define VG vector<int>, greater<int>

// variables
ll x;
ll a[70];

int main() {
    cin >> x;
    for (int i = 0; i <= 63; i++) {
        a[i] = pow(i, 5);
    }

    for (int i = 0; i <= 63; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    bool f = false;
    for (int i = 0; i <= 63; i++) {
        for (int j = 0; j <= 63; j++) {
            if (a[i] - a[j] == x) {
                cout << i << " " << j << endl;
                f = true;
                break;
            }
            if (a[i] + a[j] == x) {
                cout << i << " " << -j << endl;
                f = true;
                break;
            }
            if (a[i] + a[j] > x) break;
        }
        if (f) break;
    }

    return 0;
}