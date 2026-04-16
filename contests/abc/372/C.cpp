#include <bits/stdc++.h>
using namespace std;

int n, q, ans = 0;
string s;
int x[200009];
char c[200009];

int count(int y) {
    if (y-3 >= 0) {
        if (s.substr(y-3, 3) == "ABC") ans++;
    }
    if (y-2 >= 0 && y < n) {
        if (s.substr(y-2, 3) == "ABC") ans++;
    }
    if (y+1 < n) {
        if (s.substr(y-1, 3) == "ABC") ans++;
    }
    return ans;
}

int main() {
    cin >> n >> q;
    cin >> s;
    for (int i = 1; i <= q; i++) cin >> x[i] >> c[i];

    for (int i = 0; i < static_cast<int>(s.size()) - 2; i++) {
        if (s.substr(i, 3) == "ABC") ans++;
    }

    for (int i = 1; i <= q; i++) {
        if (x[i]-3 >= 0) {
            if (s.substr(x[i]-3, 3) == "ABC") ans--;
        }
        if (x[i]-2 >= 0 && x[i] < n) {
            if (s.substr(x[i]-2, 3) == "ABC") ans--;
        }
        if (x[i]+1 < n) {
            if (s.substr(x[i]-1, 3) == "ABC") ans--;
        }
        s[x[i]-1] = c[i];
        cout << count(x[i]) << endl;
    }
    return 0;
}