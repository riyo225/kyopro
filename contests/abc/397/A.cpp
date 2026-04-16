#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

double x;
int ans;

int main() {
    cin >> x;
    if (x >= 38.0) {
        ans = 1;
    }
    else if (x < 37.5) {
        ans = 3;
    }
    else {
        ans = 2;
    }
    cout << ans << endl;
    
    return 0;
}