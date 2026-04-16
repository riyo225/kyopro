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
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    vi a(n);
    rep(i, n) a.push_back(((int)(s[i]-"a")));
    sort(all(a));
    int ans = 0;
    bool ok, flag;

    while (true) {
        ok = true;
        rep(i, n) { 
            flag = true;
            rep(i, n) {
                if ()
            }
        }
    }
    
    
}