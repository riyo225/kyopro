#include <bits/stdc++.h>
using namespace std;

int h, w, q, r[200009], c[200009];

int main() {
    cin >> h >> w >> q;
    for (int i = 1; i <= q; i++) cin >> r[i] >> c[i];
    vector<vector<int>> a(h+1, vector<int> (w+1, 1));

    for (int i = 1; i <= q; i++) {
        if (a[r[i]][c[i]] == 1) a[r[i]][c[i]] = 0;
        else {
            for (int j = r[i]; j <= h; j++) if (a[j][c[i]] == 1) {
                a[j][c[i]] = 0;
                break;
            }
            for (int j = r[i]; j >= 1; j--) if (a[j][c[i]] == 1) {
                a[j][c[i]] = 0;
                break;
            }
            for (int j = c[i]; j <= w; j++) if (a[r[i]][j] == 1) {
                a[r[i]][j] = 0;
                break;
            }
            for (int j = c[i]; j >= 1; j--) if (a[r[i]][j] == 1) {
                a[r[i]][j] = 0;
                break;
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    vector<vector<int>> cs(h+1, vector<int> (w+1, 0));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cs[i+1][j+1] = cs[i][j+1] + cs[i+1][j] - cs[i][j] + a[i+1][j+1];
    }

    cout << cs[h][w] << endl;
}