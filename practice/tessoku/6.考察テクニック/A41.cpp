#include <bits/stdc++.h>
using namespace std;

int n;
char s[200009];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];

    bool ans = false;
    for (int i = 1; i <= n-2; i++) {
        if (s[i] == 'R' && s[i+1] == 'R' && s[i+2] == 'R') ans = true;
        if (s[i] == 'B' && s[i+1] == 'B' && s[i+2] == 'B') ans = true;
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}