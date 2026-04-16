#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    bool flag = true;
    for (int i = 0; i < s.size()-1; i++) {
        int a, b;
        a = s[i];
        b = s[i+1];
        if (a > b) {
          flag = false;
          break;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}