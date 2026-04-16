#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = n; i <= 999; i++) {
        int a, b, c;
        a = i / 100;
        b = (i - a * 100) / 10;
        c = i - b * 10 - a * 100;
        if (a * b == c) {
            cout << i << endl;
            break;
        }
    }
}