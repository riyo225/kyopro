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
int cnt = 0;

int main() {
    cin >> n;
    rrep(i, n) {
        cin >> a[i];
    }
    rrep(i, n) {
        a[i]+= (i-1);
    }

    rrep(i, n) {
        cout << a[i] << " ";
    }
    cout << endl;

    rrep(i, n) {
        if (a[i] < n-i) {
            for(int j = i+a[i]+1; j <= n; j++) {
                a[j]--;
            }
        }
    }

    rrep(i, n) {
        if (a[i]-(n-i) < 0) {
            cout << 0 << " ";
        }
        else {
            cout << a[i]-(n-i) << " ";
        }
    }
    return 0;
}