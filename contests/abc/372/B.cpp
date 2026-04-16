#include <bits/stdc++.h>
using namespace std;
#define ll long long

int m;
vector<int> vec;

void power(int x) {
    while (x > 0) {
        int y = 10;
        for (int i = y; i >= 0; i--) {
            if (x >= pow(3, i)) {
                vec.push_back(i);
                x -= pow(3, i);
                y = i;
                break;
            }
        }
    }
}

int main() {
    cin >> m;
    power(m);
    cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}