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
constexpr int INT_INF = (1 << 30);

int main() {
    string s;
    cin >> s;
    int sub = INT_INF;
    rep(i, s.size()-2) {
        int t = stoi(s.substr(i, 3));
        sub = min(sub, abs(t - 753));
    }
    cout << sub << endl;
    return 0;
}