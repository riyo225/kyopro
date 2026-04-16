#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int main() {
    ll w, a, b;
    cin >> w >> a >> b;
    if (a+w < b) cout << b - a - w << endl;
    else if (b <= a+w && a+w <= b+w) cout << 0 << endl;
    else if (a <= b+w && b+w <= a+w) cout << 0 << endl;
    else cout << a - b - w << endl;
    
    return 0;
}