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
ll x[200009], y[200009];
tuple<ll, ll, char> p[200009];
tuple<ll, ll, char> q[200009];
char c[200009];
bool ans = true;



int main() {
    cin >> n >> m;
    rrep(i, m) {
        cin >> x[i] >> y[i] >> c[i];
        p[i] = make_tuple(x[i], y[i], c[i]);
        q[i] = make_tuple(y[i], x[i], c[i]);
    }

    sort(p+1, p+m+1);
    sort(q+1, q+m+1);

    if (n >= 2) {
        rrep(i, m-1) {
            if (get<0>(p[i]) == get<0>(p[i+1])) {
                if (get<2>(p[i]) == 'W' && get<2>(p[i+1]) == 'B') {
                    ans = false;
                    break;
                }
            }
            if (get<0>(q[i]) == get<0>(q[i+1])) {
                if (get<2>(q[i]) == 'W' && get<2>(q[i+1]) == 'B') {
                    ans = false;
                    break;
                }
            }
        }
    }

    yes_no(ans);
    return 0;
}