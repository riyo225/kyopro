#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int main() {
    int n;
    cin >> n;
    bool l = false;
    int cnt = 0;
    rep(i, n) {
        string s;
        cin >> s;
        if (s == "login") l = true;
        if (s == "logout") l = false;
        if (s == "public") continue;
        if (s == "private" && !l) cnt++;
    }
    cout << cnt << endl;
    
    return 0;
}