#include <bits/stdc++.h>
using namespace std;

int n, q;
char h[109];
int t[109];

int main() {
    cin >> n >> q;
    int ans = 0;
    for (int i = 1; i <= q; i++) {
        cin >> h[i] >> t[i];
    }

    int l = 1, r = 2;
    for (int i = 1; i <= q; i++) {
        int pos, rpos;
        if (h[i] == 'R') {
            pos = r;
            rpos = l;
        }
        else {
            pos = l;
            rpos = r;
        }

        if (pos == t[i] || rpos == t[i]) {
            continue;
        }

        if (pos < t[i]) {
            if (pos < rpos && rpos < t[i]) {
                ans += n - t[i] + pos;
            }
            else {
                ans += t[i] - pos;
            }
        }
        else {
            if (t[i] < rpos && rpos < pos) {
                ans += n - pos + t[i];
            }
            else {
                ans += pos - t[i];
            }
        }
        if (h[i] == 'R') {
            r = t[i];
        }
        else {
            l = t[i];
        }
    }
    cout << ans << endl;
    return 0;
}