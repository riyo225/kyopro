#include <bits/stdc++.h>
using namespace std;

bool ans;

int main() {
    int n, k;
    cin >> n >> k;
    
    if (k < n * 2 - 2) ans = false;
    else if ((k - (n * 2 - 2)) % 2 == 0) ans = true;
    else false;

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}