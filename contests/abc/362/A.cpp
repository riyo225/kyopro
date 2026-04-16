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
    int r, g, b; cin >> r >> g >> b;
    string c; cin >> c;
    if (c == "Blue") cout << min(r, g);
    if (c == "Red") cout << min(g, b);
    if (c == "Green") cout << min(r, b);
}