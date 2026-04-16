#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Yes(b) ((b)?"Yes":"No")
#define YES(b) ((b)?"YES":"NO")
using vi = vector<int>;

signed main() {
    int y; cin >> y;
    bool a = false, b = false, c = false;
    if (y % 4 == 0) a = true;
    if (y % 100 == 0) b = true;

    if (!a) cout << 365;
    if (a && !b) cout << 366;
    if (b && !c) cout << 365;
    if (c) cout << 366;
    
}