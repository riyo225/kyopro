#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    bool c = false;
    int n = min(s.size(), t.size());
    int ans = 0;
    if (s == t) {
        ans = 0;
        c = true;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            ans = i + 1;
            c = true;
            break;
        }
    }
    if (!c) {
        ans = n + 1;
    }
    cout << ans << endl;
    
}