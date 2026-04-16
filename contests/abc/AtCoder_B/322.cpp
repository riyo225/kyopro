#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

signed main() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    
    bool front=false, back=false;

    string t_front = t.substr(0, n);
    string t_back = t.substr(m-n, n);

    if (s == t_front) {
        front = true;
    }
    if (s == t_back) {
        back = true;
    }

    if (front && back) {
        cout << 0 << endl;
    }
    else if (front && !back) {
        cout << 1 << endl;
    }
    else if (!front && back) {
        cout << 2 << endl;
    }
    else {
        cout << 3 << endl;
    }
}