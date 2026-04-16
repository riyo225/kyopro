#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, b; cin >> w >> b;
    string s = "wbwbwwbwbwbw";
    while (s.size() < w+b) {
        s += s;
    }

    bool flag = true;
    int b_count = 0;
    int w_count = 0;
    vector<int> vec(s.size(), 0);
    for (int i = 0; i < s.size() - (w+b); i++) {
        if (flag) {
            for (int j = i; j < b+w; j++) {
                if (s[j] == 'w') {
                    w_count++;
                }
                else {
                    b_count++;
                }
                if (w_count == w && b_count == b) {
                    cout << "Yes" << endl;
                    flag = false;
                    break;
                }
            }
        }
    }
    if (flag) {
        cout << "No" << endl;
    }
}