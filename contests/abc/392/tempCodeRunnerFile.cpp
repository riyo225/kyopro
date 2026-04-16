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
int a;
int A[109][100009];
double k[109];
double ans = 0;


int main() {
    cin >> n;
    rrep(i, n) {
        cin >> k[i];
        rrep(j, k[i]) {
            cin >> a;
            A[i][a]++;
        }
    }

    for (int i = 1; i <= n-1; i++) {
        for (int j = i+1; j <= n; j++) {
            ll s = 0;
            rrep(l, 120) {
                s += A[i][l]*A[j][l];
            }
            ans = max(ans, s/(k[i]*k[j]));
        }
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}