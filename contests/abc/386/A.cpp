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
bool ans = false;

int main() {
    rrep(i, 4) cin >> a[i];

    sort(a+1, a+5);

    rrep(i, 4) {
        if (a[1] == a[2]) {
            if (a[3]==a[4] && a[1]!=a[3]) ans = true; 
            if (a[1]==a[3] && a[1] != a[4]) ans = true;
        } 
        else if (a[2] == a[3]) {
            if (a[2] == a[4]) ans = true;
        }
    }
    yes_no(ans); 

    return 0;
}