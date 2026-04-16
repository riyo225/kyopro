#include <bits/stdc++.h>
using namespace std;

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
    long long a, b;
    cin >> a >> b;
    
    cout << a * b / GCD(a, b) << endl;    
    return 0;
}