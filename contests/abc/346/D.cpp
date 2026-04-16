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
    int n;
    vector<int> k(n);
    vector<int> m(n);
    vector<vector<int>> a(n);
    cin >> n;
    rep(i, n) {
        cin >> k[i];
        a.resize(k[i]);
        int mm = 0;
        rep(i, k[i]) {
            cin >> a[i][j];
            mm = max(mm, a[i][j]);
        }
        m[i] = mm;
    }

    vector<vector<int>> count(n);
    rep(i, n) {
        count.resize(m[i]);
        rep(j, m[i]) {
            count[i][a[i][j]]++;
        }
    }

    vector<double> s;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = 0; k < min(count[i].size(), count[j].size()); k++) {
                s.push_back((count[i][k] * count[j][k]) / k[i]*k[j]);
            }
        }
    }

    double ans = 0;
    for (auto v : s) {
        ans = max(v, ans);
    }

    cout << ans << endl; 
    
    return 0;
}