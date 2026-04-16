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
ll k;
char ans = '1';

int main() {
    cin >> s >> k;
    for (int i = 0; i < k; i++) {
        if (s[i] != '1') {
            ans = s[i];
            break;
        }
    }
    cout << ans << endl;
    return 0;
}