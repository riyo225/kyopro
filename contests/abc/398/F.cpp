#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

string s, t;
string A;

int main() {
    cin >> s;
    t = s;
    reverse(t.begin(), t.end());
    int n = s.size();

    int l = 0;
    int pos = 1;
    int ans = 0;
    if (s != t) {    
        for (int i = 1; i <= n-1; i++) {
            if (i%2 == 1) l++;
            if (i%2 == 0) pos++;
            string a, b;
            a = t.substr(0, l);
            b = t.substr(pos, l);
            if (a == b) {
                ans = i;
            }
        } 
    }

    // cout << "ans: " << ans << endl;

    if (ans != 0 && ans%2 == 1) {
        for (int i = 0; i < n - (ans/2) - 1; i++) {
            cout << s[i];
        }
        for (int i = n - (ans/2) - 2; i >= 0; i--) {
            cout << s[i];
        }
    }
    if (ans != 0 && ans%2 == 0) {
        for (int i = 0; i < n - (ans/2); i++) {
            cout << s[i];
        }
        for (int i = n - (ans/2) - 2; i >= 0; i--) {
            cout << s[i];
        }
    }
    if (ans == 0 && n != 1) {
        for (int i = 0; i < n-1; i++) {
            cout << s[i];
        }
        for (int i = n-1; i >= 0; i--) {
            cout << s[i];
        }
    }
    if (n == 1) cout << s << endl;

    return 0;
}