#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    bool ans = false;
    rep(i, n) {
        if (s == t) {
            ans = true;
            break;
        }#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    bool ans = false;
    rep(i, n) {
        if (s == t) {
            ans = true;
            break;
        }
        s = s[n-1] + s.substr(0, n-1);
    }
    yes_no(ans);
    return 0;
}
        s = s[n-1] + s.substr(0, n-1);
    }
    yes_no(ans);
    return 0;
}