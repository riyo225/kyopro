#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
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
int n;
ull t[109];
ull M = 1;

int main() {
    cin >> n;
    rrep(i, n) {
        cin >> t[i];
    }

    rrep(i, n) {
        M = max(M, t[i]);
    }

    rrep(i, n) {
        if (t[i] != 0) {
            if (M % t[i] != 0) {
                ull g = gcd(M, t[i]);
                if (g != 0) {
                    M *= (t[i] / g);
                }
            }
        }
    }
    cout << M << endl;
    return 0;
}