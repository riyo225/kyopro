#include <bits/stdc++.h>
using namespace std;

int h, w;
int si, sj;
int c[59][59];
string x;

int main() {
    cin >> h >> w >> si >> sj;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> c[i][j];
        }
    }
    cin >> x;
    cout << x << endl;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] == 'L') {
            if (c[si][sj-1] == '.') {
                sj--;
            }
        }
        if (x[i] == 'R') {
            if (c[si][sj+1] == '.') {
                sj++;
            }
        }
        if (x[i] == 'U') {
            if (c[si-1][sj] == '.') {
                si--;
            }
        }
        if (x[i] == 'D') {
            if (c[si+1][sj] == '.') {
                si++;
            }
        }
        cout << si << " " << sj << endl;
    }
    cout << si << " " << sj << endl;
    return 0;
}