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
int n;
string s;
int one = 0, two = 0;
bool flag = false;
bool ans = true;

int main() {
    cin >> n >> s;
    rep(i, n) {
        if (s[i] == '1' && !flag) {
            one++;
        }
        if (s[i] == '/') {
            if (flag) {
                ans = false;
                break;
            }
            flag = true;
        }
        if (s[i] == '2' && flag) {
            two++;
        }
    }
    if (one + two == n-1 && one == two) {
        ans = true;
    }
    else {
        ans = false;
    }
    yes_no(ans);
    return 0;
}