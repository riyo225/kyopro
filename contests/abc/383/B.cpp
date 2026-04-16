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
int h, w, d;
char s[19][19];
int ans = 0;


int main() {
    cin >> h >> w >> d;
    rrep(i, h) {
        rrep(j, w) {
            cin >> s[i][j];
        }
    }

    rrep(i, h) {
        rrep(j, w) {
            rrep(a, h) {
                rrep(b, w) {
                    if (s[i][j] == '.' && s[a][b] == '.') {
                        int cnt = 0;
                        rrep(k, h) {
                            rrep(l, w) {
                                if (s[k][l] == '.') {
                                    if (abs(i-k)+abs(j-l) <= d || abs(a-k)+abs(b-l) <= d) {
                                        cnt++;
                                    }
                                }
                            }
                        }
                        ans = max(ans, cnt);
                    }
                }
            }
        }
    }

    cout << ans << endl;    
    return 0;
}