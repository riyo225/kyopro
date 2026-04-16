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
int x;
int a[31630];

int main() {
    cin >> x;
    for (int i = 0; i <= 31622; i++) {
        a[i] = pow(i, 5);
    }

    int pos;
    for (int i = 0; i <= 31622; i++) {
        pos = lower_bound(a, a+31623, x) - a;
    }

    bool f = false;
    for (int i = 0; i <= pos; i++) {
        for (int j = 0; j <= pos; j++) {
            if (a[i] + a[j] == x) {
                cout << i << " " << j << endl;
                f = true;
                break;
            }
        }
        if (f) break;
    }

    return 0;
}