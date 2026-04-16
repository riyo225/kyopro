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
    int h, w;
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll> (w, 0));
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
        }
    } 
    vector<ll> row(h, 0);
    vector<ll> col(w, 0);
    rep(i, h) {
        rep(j, w) {
            row[i] += a[i][j];
        }
    }
    rep(j, w) {
        rep(i, h) {
            col[j] += a[i][j];
        }
    }

    rep(i, h) {
        rep(j, w) {
            cout << row[i] + col[j] - a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}