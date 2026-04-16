#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int main() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    bool ans = true;
    rep(i, a) {
        if (s[i] == '-') ans = false;
    }
    for (int i = a+b+1; i > a; i--) {
        if (s[i] == '-') ans = false;
    }
    if (s[a] != '-') ans = false;
    yes_no(ans);

    return 0;
}