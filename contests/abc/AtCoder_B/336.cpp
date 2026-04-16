#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    bitset<31> bs(n);
    cout << bs << endl;
    int count = 0;
    string ans = stoi(bs);
    for (int i = 31; i >= 0; i--) {
        if (ans[i] == '0') {
            count++;
        }
        else {
            break;
        }
    }
    cout << count << endl;
    cout << bs << endl;
}