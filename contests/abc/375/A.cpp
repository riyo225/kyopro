#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s.substr(i, 3) == "#.#") {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}