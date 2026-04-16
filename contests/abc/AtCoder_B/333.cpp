#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec(4);
    for (int i = 0; i < 4; i++) {
        char c; cin >> c;
        vec[i] = c - 97;
    }
    int a = abs(vec[0] - vec[1]);
    int b = abs(vec[2] - vec[3]);
    if (a > 2) {
        a = 5 - a;
    } 
    if (b > 2) {
        b = 5 - b;
    }

    if (a == b) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}