#include <bits/stdc++.h>
using namespace std;

#define ll long long

int a[30];

int main() {
    bool ans = true;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        int j = c - 48 - 16;
        a[j]++;
    }
    for (int i = 1; i <= s.size(); i++) {
        if (a[i] != 1) {
            ans = false;
        }
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}