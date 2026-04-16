#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
// sortmacro
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define GT greater<int>()
// priority_queue
#define VG vector<int>, greater<int>

// variables
string s;

int main() {
    cin >> s;
    while (!s.empty()) {
        s.pop_back();
        if (s.size() % 2 == 0) {
            int n = s.size() / 2;
            if (s.substr(0, n) == s.substr(n, n)) {
                cout << n*2 << endl;
                break;
            }
        }
    }

    return 0;
}