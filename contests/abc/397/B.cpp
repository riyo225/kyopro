#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

string s;
int ans = 0;
bool flag = true;

int main() {
    cin >> s;

    rep(i, s.size()) {
        if (flag) {
            if ((i+ans)%2 == 0 && s[i] != 'i') {
                ans++;    
            }
            if ((i+ans)%2 == 1 && s[i] != 'o') {
                ans++;    
            }
        }
    }
    if (s[s.size()-1] == 'i') {
        ans++;
    }

    cout << ans << endl;
    
    return 0;
}