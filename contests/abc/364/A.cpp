#include <bits/stdc++.h>
using namespace std;

int n;
string s[109];

int main() {
    cin >> n;
    bool ans = true;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    string pos = s[1];
    for (int i = 2; i <= n; i++) {
        if (pos == "sweet" && s[i] == "sweet") {
            if (i != n) ans = false;
            break;
        }
        pos = s[i];
    }

    if (ans) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

}