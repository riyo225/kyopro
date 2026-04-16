#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main() {
    cin >> a >> b >> c;

    if (b > c) {
        c += 24;
        if (a < b) a += 24;
    }

    if (a < b || c < a) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0; 
}