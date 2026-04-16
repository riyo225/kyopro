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
char s[59][59];

int main() {
    cin >> n;
    rrep(i, n) {
        int j = n+1-i;
        if (i <= j) {
            if (i%2==1) {
                for (int x = i; x <= j; x++) {
                    for (int y = i; y <= j; y++) {
                        s[x][y] = '#';
                    }
                }
            }
            else {
                for (int x = i; x <= j; x++) {
                    for (int y = i; y <= j; y++) {
                        s[x][y] = '.';
                    }
                }
            }
        }
    }

    rrep(i, n) {
        rrep(j, n) {
            cout << s[i][j];
        }
        cout << endl;
    }

    return 0;
}