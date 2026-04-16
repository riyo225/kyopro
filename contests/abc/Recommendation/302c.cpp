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
int n, m;
string s[10];
bool ans = true;
int c[10][10];

int main() {
    cin >> n >> m;
    rrep(i, n) cin >> s[i];

    rrep(i, n-1) {
        for (int j = i+1; j <= n; j++) {
            int cnt = 0;
            rep(k, m) {
                if (s[i][m] != s[j][m]) {
                    cnt++;
                }
            }
            c[i][j] = cnt;
        } 
    }
    rrep(i, n-1) {
        for (int j = i+1; j <= n; j++) {
            if (c[i][j] == 1) ;
            if 
        }
    }
    yes_no(ans);

    return 0;
}