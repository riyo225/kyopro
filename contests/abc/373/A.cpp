#include <bits/stdc++.h>
using namespace std;

string s;
int sum = 0;

int main() {
    for (int i = 2; i <= 12; i++) {
        cin >> s;
        if (s.size() == i) sum++;
    }
    cout << sum << endl;
    return 0;
}