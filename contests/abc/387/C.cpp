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
ll l, r;
int ds, dg; 
int ms, mg;
ll ans = 0;

int main() {
    cin >> l >> r;
    ll L = l;
    ll R = r;

    while (L > 0) {
        L /= 10;
        ds++;
    }
    while (R > 0) {
        R /= 10;
        dg++;
    }


    ms = l / pow(10, ds-1);
    mg = r / pow(10, dg-1);

    
    for (int i = ds; i <= dg; i++) {
        int j;
        if (i == ds) {
            j = ms;
        }
        else {
            j = 1;
        }

        int la;
        if (i == dg) {
            la = mg;
        }
        else {
            la = 9;
        }

        for (int k = j; k <= la; k++) {
            if (k != j || k != la) {
                ans += pow(k, i-1);
            }
            cout << i << " " << k << endl;
        }
    }

    for (int i = l; i <= (ms+1)*pow(10, ms-1); i++) {
        
    }


    
    cout << ans << endl;
    return 0;
}