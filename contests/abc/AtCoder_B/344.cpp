#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vec(110, -1);
    for (int i = 0; i < 110; i++) {
        cin >> vec[i];
    }

    for (int i = 109; i >= 0; i--) {
        if (vec[i] != -1) {
            cout << vec[i] << endl;
        }
    }
}