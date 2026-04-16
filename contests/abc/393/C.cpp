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
    int n, m;
    cin >> n >> m;
    vector<int> u(m);
    vector<int> v(m);
    rep(i, m) {
        cin >> u[i] >> v[i];
        if (u[i] > v[i]) swap(u[i], v[i]);
    }

    set<pair<int, int>> s;
    rep(i, m) s.insert({u[i], v[i]});
    int cnt = 0;
    for (auto [fi, se] : s) {
        if (fi == se) {
            cnt++;
        }
    }

    cout << m - s.size() + cnt << endl;

    return 0;
}