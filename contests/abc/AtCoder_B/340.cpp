#include <bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;
    vector<int> vec;
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        if (a == 1) {
            vec.push_back(b);
        }
        else {
            cout << vec[vec.size() - b] << endl;
        }
    }
}