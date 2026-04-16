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
int a[10];
int cnt = 0;
int cntt = 0;

int main() {
    rrep(i, 5) {
        cin >> a[i];
        if (i == a[i]) cntt++;
    }

    rrep(i, 4) {
        if (a[i] > a[i+1]) {
            cnt++;
        }
    }

    if (cnt==1 && cntt==3) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}