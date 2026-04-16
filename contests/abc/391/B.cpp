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
    vector<vector<char>> s(n, vector<char> (n));
    vector<vector<char>> t(m, vector<char> (m));

    rep(i, n) {
        rep(j, n) {
            cin >> s[i][j];
        }
    }

    rep(i, m) {
        rep(j, m) {
            cin >> t[i][j];
        }
    }

    int c, d;
    for (int i = 0; i < n-m+1; i++) {
        for (int j = 0; j < n-m+1; j++) {
            bool ans = true;
            int a=i, b=j, x=0, y=0;
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < m; y++) {
                    if (s[i+x][j+y] != t[x][y]) ans = false;
                }
            }

            if (ans) {
                c = i;
                d = j;
            }
        }
    }

    cout << c+1 << " " << d+1 << endl;
    
    return 0;
}