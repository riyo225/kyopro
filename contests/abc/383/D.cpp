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
ll N;
ll ans = 0;

int main() {
    cin >> N;
    ll n = sqrt(N);
    cout << n << endl;
    for(int i = 2; i <= n / 2; i++) {
        for (int j = i+1; j <= n / 2; j++) {
            if (j % i != 0) {
                if (i*j <= n) {
                    ans++;
                    cout << i << " " << j << endl;
                }
            }
        }
    }
    cout << ans << endl;
}