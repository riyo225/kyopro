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
int a, b, n;

int main() {
    cin >> a >> b >> n;

    int x = min(a, b);
    for (int i = n; i <= x*n; i++) {
        if (i%a==0 && i%b==0) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}