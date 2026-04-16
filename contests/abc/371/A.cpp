#include <bits/stdc++.h>
using namespace std;

char a, b, c;

int main() {
    cin >> a >> b >> c;
    if (a == '<') {
        if (c == '<') cout << 'B' << endl;
        else {
            if (b == '<') cout << 'C' << endl;
            else cout << 'A' << endl;
        }
    }
    else {
        if (b == '<') cout << 'A' << endl;
        else {
            if (c == '<') cout << 'C' << endl;
            else cout << 'B' << endl;
        }
    }
}