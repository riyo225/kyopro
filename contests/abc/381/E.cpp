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
int q;
int one = 0, two = 0;
bool f = false;
int ans = 0;
int a[100009];
int b[100009];
int l, r;
vector<int> c;
vector<int> d;

int main() {
    cin >> n >> q >> s;

    rep(i, n) {
        if (s[i] == '1') {
            one++;
            c.push_back(one);
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
                ans = max(ans, 1);
            }
        }
        a[i+1] = ans;
    }
    f = false;
    one = 0;
    two = 0;
    ans = 0;
    for (int i = n-1; i >= 0; i--) {
        if (f == false) {
            if (s[i] == '1') {
                one = 0;
            }
            if (s[i] == '2') {
                one++;
            }
            if (s[i] == '/') {
                f = true;
                ans = max(ans, 1);
                b[i+1] = ans;
                continue;
            }
        }
        if (f == true) {
            if (s[i] == '1') {
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
            if (s[i] == '2') {
                one = 1;
                two = 0;
                f = false;
            }
            if (s[i] == '/') {
                one = 0;
                two = 0;
                f = false;
                ans = max(ans, 1);
            }
        }
        b[i+1] = ans;
    }

    rrep(i, q) {
        cin >> l >> r;
        cout << min(a[r-1],  b[l-1]) << endl;
    }



    return 0;
}