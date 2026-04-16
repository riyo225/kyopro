#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t; cin >> s >> t;
    bool flag = false;
    for (int w = 1; w < s.size(); w++) {
        for (int fi = 0; fi < w; fi++) {
            string korekirai = "";
            for (int i = 0; i < s.size(); i++) {
                if (i % w == fi) {
                    korekirai += s[i];
                }
            }
            if (korekirai == t) {
                flag = true;
            }

        }
    }
    if (flag) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}