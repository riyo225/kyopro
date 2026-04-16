#include <bits/stdc++.h>
using namespace std;

int n, l, r, h;
int a[109];
char s[109];
int lcount = 0, rcount = 0;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] >> s[i];

    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L') {
            if (lcount != 0) {
                h += abs(a[i] - l) 
            }
            l = a[i];
            lcount++;
        }
        else {
            if (rcount != 0) {
                h += abs(a[i] - r);
            }
            r = a[i];
            rcount++;
        }
    }
    cout << h << endl;
    return 0;
}