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
int t[109], v[109];
int pos = 0;
int ti = 1;

int main() {
    cin >> n;
    rrep(i, n) cin >> t[i] >> v[i];


    rrep(i, t[n]) {
        if (pos > 0) {
            pos--;
        }
        if (i == t[ti]) {
            pos += v[ti];
            ti++;
        }
    }

    cout << pos << endl;


    return 0;
}