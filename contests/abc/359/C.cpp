#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int s_x, s_y; cin >> s_x >> s_y;
    int t_x, t_y; cin >> t_x >> t_y;

    int h = abs(t_y - s_y);
    int w = abs(t_x - s_x);
    int wr = t_x - s_x;
    int add = s_x + s_y;
    int l, r;
    int count = h;
    if (add % 2 == 0) {
        l = s_x - h;
        r = s_x + h + 1;
        if (l <= t_x && r >= t_x) {
            cout << h << endl;
        }
        else {
            if (wr > 0) {
                cout << h + (t_x - r + 1) / 2 << endl;
            }
            else {
                cout << h + (l - t_x + 1) / 2 << endl;
            }
        }
    }
    else {
        l = s_x - h - 1;
        r = s_x + h;
        if (l <= t_x && r >= t_x) {
            cout << h << endl;
        }
        else {
            if (wr > 0) {
                cout << h + (t_x - r + 1) / 2 << endl;
            }
            else {
                cout << h + (l - t_x + 1) / 2 << endl;
            }
        }
    }
}