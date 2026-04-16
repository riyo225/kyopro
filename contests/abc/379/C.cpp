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
ll x[200009], a[200009];
ll have = 0;
ll sum = 0;
map <ll, ll> ma;

int main() {
    cin >> n >> m;
    rrep(i, m) cin >> x[i];
    rrep(i, m) cin >> a[i];

    rrep(i, m) {
        ma.insert(x[i], a[i]);
    }

    rrep(i, n) {
        if (ma.contains(i)) {
            have += ma[i];
        }
        else {
            sum += 
        }
    }

   




    return 0;
}