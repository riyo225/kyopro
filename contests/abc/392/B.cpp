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
int n, m;
int a[1009];
bool b[1009];
int cnt = 0;

int main() {
    cin >> n >> m;
    rrep(i, n) b[i] = false;
    rrep(i, m) {
        cin >> a[i];
        b[a[i]] = true;
    }

    rrep(i, n) {
        if (b[i]) cnt++;
    }

    if (cnt != n) {
        cout << n-cnt << endl;
        rrep(i, n) {
            if (!b[i]) {
                cout << i << " ";
            }
        }
    }
    else {
        cout << 0 << endl;
        cout << endl;
    }




    return 0;
}