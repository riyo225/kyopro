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
int n, d;
int t[109], l[109];
int ans = 0;

int main() {
    cin >> n >> d;
    rrep(i, n) {
        cin >> t[i] >> l[i];
    }

    rrep(i, d) {
        ans = 0;
        rrep(j, n) {
            ans = max(ans, t[j]*(l[j]+i));
        }
        cout << ans << endl;
    }


    return 0;
}