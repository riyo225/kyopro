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
int n;
int h[3009];
int ans = 0;

int main() {
    cin >> n;
    rrep(i, n) cin >> h[i];

    rrep(i, n-1) {
        rrep(j, n-i) {
            int cnt = 1;
            int pos = i;
            int nex = i+j;
            while (h[pos] == h[nex] && nex <= n) {
                cnt++;
                nex += j;
            }
            ans = max(ans, cnt);
        }
    }

    cout << ans << endl;
    return 0;
}