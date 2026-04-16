#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> x(h, vector<int> (w, 0));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> x[i][j];
        }
    }
    int q;
    cin >> q;

    vector<vector<int>> cs(h+1, vector<int> (w+1, 0));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cs[i+1][j+1] = cs[i][j+1] + cs[i+1][j] - cs[i][j] + x[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int area = cs[c][d] - cs[c][b-1] - cs[a-1][d] + cs[a-1][b-1];
        cout << area << endl;
    }
}