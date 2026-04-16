#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ans = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        int num = s[i] - '0';
        ans += num * (1 << (s.size() - i) - 1);
    }
    cout << ans << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     string s;
//     cin >> s;

//     int ans = stoi(s, nullptr, 2);
//     cout << ans << endl;
// }