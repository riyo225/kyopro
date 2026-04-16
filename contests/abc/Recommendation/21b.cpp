#include <bits/stdc++.h>
using namespace std;

// macro
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
// sortmacro
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define GT greater<int>()

// variables
int n, a, b, k;
vector<int> p;
bool ans = true;

int main() {
    cin >> n >> a >> b >> k;
    p.push_back(a);
    p.push_back(b);
    rrep(i, k) {
        int c;
        cin >> c;
        p.push_back(c);
    }

    sort(all(p));

    rep(i, k+1) {
        if (p[i] == p[i+1]) {
            ans = false;
            break;
        }
    }

    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}