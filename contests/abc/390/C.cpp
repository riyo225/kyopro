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
int h, w;
string s[1009];
int r=0; int l=1000; int t=1000; int b=0;
bool ans = true;

int main() {
    cin >> h >> w;
    rrep(i, h) {
        cin >> s[i];
    }

    rrep(i, h) {
        rep(j, w) {
            if (s[i][j] == '#') {
                r = max(r, j);
                l = min(l, j);
                t = min(t, i);
                b = max(b, i);
            }
        } 
    }

    for (int i = t; i <= b; i++) {
        for (int j = l; j <= r; j++) {
            if (s[i][j] == '.') {
                ans = false;
            }
        }
    }

    yes_no(ans);

    return 0;
}