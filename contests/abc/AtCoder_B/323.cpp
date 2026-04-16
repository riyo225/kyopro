#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define re
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);
constexpr int INT_INF = (1 << 30);

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    map<int, vector<int>> mp;
    rep(i, n) cin >> s[i];
    rep(i, n) {
        int cnt = 0;
        rep(j, n) {
            if (s[i][j] == 'o') {
                cnt++;
            }
        }
        mp[cnt].push_back(i);
    }
    vector<pair<int, vector<int>>> vec(mp.begin(), mp.end());
    sort(rall(vec));
    for (auto [k, v] : vec) {
        sort(all(v));
        rep(i, v.size()) {
            cout << v[i]+1 << " ";
        }
    }
    cout << endl;
    return 0;
}