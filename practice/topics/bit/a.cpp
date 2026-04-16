#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 45;
    int b = 25;
    // AND
    cout << (a&b) << endl;
    // OR
    cout << (a|b) << endl;
    // bitset
    cout << bitset<8>(a&b) << endl;
    cout << bitset<8>(a|b) << endl;
    // ビットシフト
    // a番目にフラグが立っている => (1<<a)
    // a, b, c番目にフラグが立っている => (1<<a)|(1<<b)|(1<<c)
    return 0;    
}