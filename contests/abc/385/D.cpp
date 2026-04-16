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
int n, m, sx, sy;
int x[200009], y[200009];
char d[200009];
int c[200009];
bool is[200009];
int cnt = 0;

int main() {
    cin >> n >> m >> sx >> sy;
    rrep(i, n) {
        cin >> x[i] >> y[i];
    }
    rrep(i, m) {
        cin >> d[i] >> c[i];
    }
    rrep(i, n) {
        is[i] = false;
    }

    rrep(i, m) {
        if (d[i] == 'U') {
            rrep(j, n) {
                if (sy <= y[j] && y[j] <= sy+c[i] && x[i] == sx) {
                    if (!is[j]) {
                        is[j] = true;
                        cnt++;
                    }
                    cnt++;
                }
            }
            sy += c[i];
        }
        if (d[i] == 'D') {
            rrep(j, n) {
                if (sy-c[i] <= y[j] && y[j] <= sy && x[i] == sx) {
                    if (!is[j]) {
                        is[j] = true;
                        cnt++;
                    }
                    cnt++;
                }
            }
            sy -= c[i];
        }
        if (d[i] == 'L') {
            rrep(j, n) {
                if (sx-c[i] <= x[j] && x[j] <= sx && y[i] == sy) {
                    if (!is[j]) {
                        is[j] = true;
                        cnt++;
                    }
                    cnt++;
                }
            }
            sx -= c[i];
        }
        if (d[i] == 'R') {
            rrep(j, n) {
                if (sx <= x[j] && x[j] <= sx+c[i] && y[i] == sy) {
                    if (!is[j]) {
                        is[j] = true;
                        cnt++;
                    }
                    cnt++;
                }
            }
            sx += c[i];
        }
    }
    cout << sx << " " << sy << " " << cnt << endl;
    
    return 0;
}