#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '.') cout << s[i];
    }
    cout << endl;
    return 0;
}