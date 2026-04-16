#include <bits/stdc++.h>
using namespace std;

int l, r;

int main() {
    cin >> l >> r;
    if (l == 1) {
        if (r == 1) cout << "Invalid" << endl;
        else cout << "Yes" << endl;
    }
    else {
        if (r == 1) {
            cout << "No" << endl;
        }
        else {
            cout << "Invalid" << endl;
        }
    }
}