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
    int a, b;
    cin >> a >> b;
    if (a == b) cout << "Draw" << endl;
    else if (a == 1) cout << "Alice" << endl;
    else if (b == 1) cout << "Bob" << endl;
    else if (a > b) cout << "Alice" << endl;
    else if (a < b) cout << "Bob" << endl;
    return 0;
}