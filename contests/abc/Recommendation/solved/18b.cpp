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
string s;
int n;
int l[109], r[109];

int main() {
    cin >> s >> n;
    rrep(i, n) cin >> l[i] >> r[i];

    rrep(i, n) {
        int m = (r[i] - l[i]) / 2 + 1;
        for (int j = 0; j < m; j++) {
            swap(s[l[i]+j-1], s[r[i]-j-1]);
        }
    }
    cout << s << endl;

    return 0;
}