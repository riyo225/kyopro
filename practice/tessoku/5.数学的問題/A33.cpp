// これって丸暗記なんですかね...
#include <bits/stdc++.h>
using namespace std;

int n;
int a[100009];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int XOR_sum = a[1];
    for (int i = 2; i <= n; i++) XOR_sum = (XOR_sum ^ a[i]);

    if (XOR_sum != 0) cout << "First" << endl;
    if (XOR_sum == 0) cout << "Second" << endl;
    return 0;
}