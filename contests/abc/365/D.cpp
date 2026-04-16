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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> vec(n);

    rep(i, n) {
        if (s[i] == 'R') vec[i] = 'P';
        if (s[i] == 'P') vec[i] = 'S';
        if (s[i] == 'S') vec[i] = 'R';
        
    }
}