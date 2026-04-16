#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
// sortmacro
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define GT greater<int>()
// priority_queue (smallest order)
#define VG vector<int>, greater<int>

// variables
int n;
int x[509], y[509];
set<pair<int, int>> s;

int main() {
    cin >> n;
    rrep(i, n) cin >> x[i] >> y[i];

    for (int i = 1; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            int dy = y[j]-y[i];
            int dx = x[j]-x[i];
            int g = gcd(dy, dx);
            dy /= g;
            dx /= g;
            s.insert({dx, dy});
            s.insert({-dx, -dy});
        }
    }

    cout << s.size() << endl;
    return 0;
}