#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x; cin >> x;
    if (x % 10 == 0 || x < 0) {
        cout << x / 10 << endl;
    }
    else {
        cout << x / 10 + 1 << endl; 
    }
}