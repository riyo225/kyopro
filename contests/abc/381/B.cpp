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
map<char, int> m; 
bool ans = true;

int main() {
    cin >> s;
    int n = s.size();
    if (n % 2 != 0) {
        ans = false;
    }

    rep(i, n) {
        m[s[i]]++;
    }

    for (int i = 0; i <= n/2; i++) {
        if (s[2*i] != s[2*i+1]) {
            ans = false;
        }
    }

    rep(i, n) {
        if (m[s[i]] != 2) {
            ans = false;
        }
    }
    yes_no(ans);

    return 0;
}