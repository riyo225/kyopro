#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    bool ans = false;
    if (b-a == c-b) ans = true;
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}