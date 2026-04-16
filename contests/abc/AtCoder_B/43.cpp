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
    string s;
    cin >> s;
    vector<char> v;
    rep(i, s.size()) {
        if (s[i] == '0') v.push_back('0');
        if (s[i] == '1') v.push_back('1');
        if (s[i] == 'B') {
            if (v.size() != 0) v.pop_back();
        }
    }
    rep(i, v.size()) {
        cout << v[i];
    }
    cout << endl;
    return 0;
}