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
int a[5];
int b[5];

int main() {
    rep(i, 4) {
        cin >> a[i];
    }
    int cnt = 0;
    rep(i, 4) {
        b[a[i]]++;
    }

    rrep(i, 4) {
        cnt += b[i] / 2;
    }


    cout << cnt << endl;

    return 0;
}