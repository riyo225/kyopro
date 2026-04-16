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
int n;
int a[500009];
int c[500009];
int d[500009];

int main() {
    cin >> n;
    rrep(i, n) {
        cin >> a[i];
    }

    rrep(i, n) {
        c[i] = c[i-1] + d[i];
        a[i] += c[i];
        d[i+1]++;
        d[min(n+1, a[i]+i+1)]--;
        // cout << a[i] << " ";
    }
    // cout << endl;

    rrep(i, n) {
        if (a[i] < n-i) {
            cout << 0 << " ";
        }
        else {
            cout << a[i] - n + i << " ";
        }
    }
    cout << endl;

    // rrep(i, n+1) {
    //     cout << d[i] << " ";
    // }
    // cout << endl;
 
    
    return 0;
}