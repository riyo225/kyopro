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
int h, w, x, y;
int cnt = 0;
char s[109][109];
bool ho[109][109];
string t;

int main() {
    cin >> h >> w >> x >> y;
    rrep(i, h) {
        rrep(j, w) {
            cin >> s[i][j];
        }
    }
    cin >> t;
    rrep(i, h) {
        rrep(j, w) {
            ho[i][j] = false;
        }
    }
    rrep(i, h) {
        rrep(j, w) {
            if (s[i][j] == '@') {
                ho[i][j] = true;
            }
        }
    }

    rep(i, t.size()) {
        if (t[i] == 'U') {
            if (s[x-1][y] != '#') {
                if (s[x-1][y] == '@' && ho[x-1][y] == true) {
                    cnt++;
                    ho[x-1][y] = false;
                }
                x--;
            } 
        }
        if (t[i] == 'D') {
            if (s[x+1][y] != '#') {
                if (s[x+1][y] == '@' && ho[x+1][y] == true) {
                    cnt++;
                    ho[x+1][y] = false;
                }
                x++;
            } 
        }
        if (t[i] == 'L') {
            if (s[x][y-1] != '#') {
                if (s[x][y-1] == '@' && ho[x][y-1] == true) {
                    cnt++;
                    ho[x][y-1] = false;
                }
                y--;
            } 
        }
        if (t[i] == 'R') {
            if (s[x][y+1] != '#') {
                if (s[x][y+1] == '@' && ho[x][y+1] == true) {
                    cnt++;
                    ho[x][y+1] = false;
                }
                y++;
            } 
        }
    }
    cout << x << " " << y << " " << cnt << endl;
    return 0;
}