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
int p[300009], q[300009];
tuple<int, int, int> t[300009];

int main() {
    cin >> n;
    rrep(i, n) {
        cin >> p[i];
    }
    rrep(i, n) {
        cin >> q[i];
    }
    rrep(i, n) {
        t[i] = make_tuple(q[i], i, p[i]);
    }

    sort(t+1, t+n+1);

    rrep(i, n) {
        cout << q[get<2>(t[i])] << " ";
    }
    cout << endl;

    return 0;
}