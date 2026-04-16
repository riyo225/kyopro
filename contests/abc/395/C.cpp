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
int a[200009];
map<int, vector<int>> m;
int ans = 1111111;

int main() {
    cin >> n;
    rrep(i, n) {
        cin >> a[i];
        m[a[i]].push_back(i);
    }

    rrep(i, m.size()) {
        if (m[i].size() > 1) {
            rep(j, m[i].size()-1) {
                ans = min(m[i][j+1]-m[i][j], ans);
            }
        }
    }

    if (ans == 1111111) {
        cout << -1 << endl;
    }
    else {
        cout << ans+1 << endl;
    }



    return 0;
}