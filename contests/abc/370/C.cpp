#include <bits/stdc++.h>
using namespace std;

string s, t;
vector<string> x;

int main() {
    cin >> s >> t;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] > t[i]) {
            s[i] = t[i];
            x.push_back(s);
        }
    }

    for (int i = s.size(); i >= 0; i--) {
        if (s[i] != t[i]) {
            s[i] = t[i];
            x.push_back(s);
        }
    }
    

    cout << x.size() << endl;
    for (int i = 0; i < x.size(); i++) cout << x[i] << endl;
}