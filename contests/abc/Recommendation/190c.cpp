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
int a[109], b[109];
int k;
int c[109], d[109];

bool is_existed[109];

int main() {
    cin >> n >> m;
    rrep(i, m) {
        cin >> a[i] >> b[i];
    }
    cin >> k;
    rrep(i, k) {
        cin >> c[i] >> d[i];
    }

    rrep(i, n) {
        is_existed[i] = false;
    }

    



    return 0;
}