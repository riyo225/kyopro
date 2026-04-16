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
ll n, m;
ll p[200009];
ll ans = 0;

int main() {
    cin >> n >> m;
    rrep(i, n) {
        cin >> p[i];
    }

    sort(p+1, p+n+1);

    int i = 1;
    while(m - p[i] > 0) {
        ll x = 1;
        while(x*x*p[i] < p[i+1] && m - x*x*p[i] > 0) {
            x++;
        }
        m -= x*x*p[i];
        ans += x;
        i++;
    }

    cout << ans << endl;


    return 0;
}