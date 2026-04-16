#include <bits/stdc++.h>
using namespace std;


int main() {
    string s; cin >> s;
    int a;
    int b;
    for (int i = 0; i < 3; i++) {
        if (s[i] == 'M') {
            a = i;
        }
        if (s[i] == 'R') {
            b = i;
        }
    }
    if (a > b) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}