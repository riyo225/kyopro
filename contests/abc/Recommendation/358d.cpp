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

#define VG vector<int>, greater<int>

// variables
int n, m;
int a[200009];
priority_queue<int, VG> pq;
ll ans = 0;

int main() {
    cin >> n >> m;
    rrep(i, n) cin >> a[i];
    rrep(i, m) {
        int b;
        cin >> b;
        pq.push(b);
    }

    sort(a+1, a+n+1);

    int x = pq.top();
    rrep(i, n) {
        if (x <= a[i]) {
            ans += a[i];
            pq.pop();
            if (!pq.empty()) {
                x = pq.top();
            }
            else {
                break;
            }
        }

        if (i == n && !pq.empty()) {
            ans = -1;
        }
    }

    cout << ans << endl;
    return 0;
}