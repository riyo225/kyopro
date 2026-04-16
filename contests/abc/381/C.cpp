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
bool f = false;
int ans = 1;

int main() {
    cin >> n >> s;

    rep(i, n) {
        if (f == false) {
            if (s[i] == '2') {
                one = 0;
            }
            if (s[i] == '1') {
                one++;
            }
            if (s[i] == '/') {
                f = true;
                continue;
            }
        }
        if (f == true) {
            if (s[i] == '2') {
                two++;
                if (one >= two) {
                    ans = max(ans, two*2+1);
                    if (one == two) {
                        one = 0;
                        two = 0;
                        f = false;
                    }
                }
            }
            if (s[i] == '1') {
                one = 1;
                two = 0;
                f = false;
            }
            if (s[i] == '/') {
                one = 0;
                two = 0;
                f = false;
            }
        }
    }
    cout << ans << endl;


    return 0;
}