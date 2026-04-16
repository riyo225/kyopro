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
    char b;
    cin >> b;
    if (b == 'A') cout << 'T' << endl;
    if (b == 'T') cout << 'A' << endl;
    if (b == 'C') cout << 'G' << endl;
    if (b == 'G') cout << 'C' << endl;
    return 0;
}