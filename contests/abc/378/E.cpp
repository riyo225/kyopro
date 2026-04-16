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
int n, m;
int a[200009];
int cs[200009];
int css[200009];

int main() {
    cin >> n >> m;
    rrep(i, n) cin >> a[i];

    cs[0] = 0;
    css[0] = 0;
    rrep(i, n) {
        cs[i] = cs[i-1] + a[i];
    }
    rrep(i, n) {
        cs[i] %= m;
    }
    rrep(i, n) {
        css[i] = css[i-1] + cs[i];
    }

    return 0;
}