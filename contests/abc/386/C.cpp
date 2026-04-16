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
int k;
string s, t;
bool ans = false;
int cnt = 0;

int main() {
    cin >> k;
    cin >> s >> t;
    int a = max(s.size(), t.size());
    if (s == t) ans = true;
    else if ((s.size() - t.size()) == 1 || s.size() - t.size() == -1 || s.size() - t.size() == 0) {
        rep(i, s.size()) {
            if (s[i] == t[i]) {
                cnt++;
            }
            else {
                break;
            }
        }
        if (cnt != a-1) {
            for (int i = a-1; i >= 1; i--) {
                if (s.size() > t.size()) {
                    if (s[i] == t[i-1]) {
                        cnt++;
                    }
                    else {
                        break;
                    }
                }
                else if (s.size() < t.size()) {
                    if (s[i-1] == t[i]) {
                        cnt++;
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (s[i] == t[i]) {
                        cnt++;
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }

    if (cnt == a-1) ans = true;
    yes_no(ans);
    return 0;
}