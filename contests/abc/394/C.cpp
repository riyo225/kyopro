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
int main() {
    cin >> s;
    for (int i = s.size(); i > 0; i--) {
        if (s[i] == 'A' && s[i-1] == 'W') {
            s[i] = 'C', s[i-1] = 'A';
        }
    }

    cout << s << endl;
    
    return 0;
}