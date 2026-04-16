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
int a[1009];
bool ans = true;

int main() {
    cin >> n;
    rrep(i, n) {
        cin >> a[i];
    }
    rrep(i, n-1) {
        if (a[i] >= a[i+1]) ans = false;
    }
    yes_no(ans);
    return 0;
}