#include <bits/stdc++.h>
using namespace std;

int n, q;
int t[109];
char h[109];

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> t[i];
    }

    int l = 1, r = 2;
    long long ans = 0;
    bool rr = true;
    for (int i = 1; i <= q; i++) {
        int pos, s;
        int nex = t[i];
        if (h[i] == 'R') {
            pos = r;
            s = l;
            rr = true;
        }
        else {
            pos = l;
            s = r;
            rr = false;
        }

        if (pos < nex) {
            if (pos < s && s < nex) {
                ans += n-(nex-pos);
            }
            else {
                ans += nex-pos;
            }
        }
        else {
            if (nex < s && s < pos) {
                ans += n-(pos-nex);
            }
            else {
                ans += pos-nex;
            }
        }

        if (rr) {
            r = nex;
        }
        else {
            l = nex;
        }
    }

    cout << ans << endl;    
    return 0;
}