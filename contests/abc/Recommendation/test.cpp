#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s = {2, 3, 5, 1, 4};

    for (auto c : s) {
        cout << c << " ";
    }
    cout << endl;

    s.erase(s.begin());

    cout << *s.begin() << endl;
    cout << *s.end() << endl;
    cout << *s.find(4) << endl;
}