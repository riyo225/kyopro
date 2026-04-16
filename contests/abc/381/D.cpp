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
int cnt = 0;
map<int, int> m;
int ans = 0;

int main() {
    cin >> n;
    rep(i, n) cin >> a[i];

    rep(i, n) {
        if (a[i] == a[i+1] && i % 2 == 0) {
            if (m[a[i]] == 0) {
                cnt+=2;
                m[a[i]] = 2;
                ans = max(ans, cnt);
            }
            else {
                ans = max(ans, cnt);
                cnt = 2;
                m.clear();
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;

    
    

    return 0;
}