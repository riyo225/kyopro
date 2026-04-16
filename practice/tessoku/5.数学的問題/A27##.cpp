#include <bits/stdc++.h>
using namespace std;

int a, b;

int GCD(int a, int b) {
    while (min(a, b) > 0) {
        int r = max(a, b) % min(a, b);
        if (a > b) a = r;
        else b = r;
    }
    if (a == 0) return b;
    else return a;
    return 1;
}

int main() {
    cin >> a >> b;
    
    cout << GCD(a, b) << endl;
    return 0;
}