#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int n;
string s[59];
vector<pair<int, string>> p;

int main() {
    cin >> n;
    rrep(i, n) cin >> s[i];
    rrep(i, n) {
        p.push_back({s[i].size(), s[i]});
    }
    sort(p.begin(), p.end());
    rep(i, p.size()) {
        cout << p[i].second;
    }
    cout << endl;
    return 0;
}