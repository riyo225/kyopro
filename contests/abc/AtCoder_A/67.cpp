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
    int a, b;
    cin >> a >> b;
    bool ans = false;
    if (a >= 3 && a % 3 == 0) ans = true;
    if (b >= 3 && b % 3 == 0) ans = true;
    if (a+b >= 3 && (a+b) % 3 == 0) ans = true;
    if (ans) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    return 0;
}