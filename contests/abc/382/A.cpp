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

int n, d;
string s;
int cnt = 0;

int main() {
    cin >> n >> d >> s;

    rep(i, n) {
        if (s[i] == '.') {
            cnt++;
        }
    }
    cout << cnt + d << endl;


    return 0;
}