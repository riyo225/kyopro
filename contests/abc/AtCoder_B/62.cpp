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
    vector<vector<char>> a(h, vector<char> (w));
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
        }
    }

    for (int i = -1; i < h+1; i++) {
        for (int j = -1; j < w+1; j++) {
            if (i == -1 || j == -1 || i == h || j == w) cout << '#';
            else cout << a[i][j];
        }
        cout << endl;
    }
    return 0;#include <bits/stdc++.h>
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
    vector<vector<char>> a(h, vector<char> (w));
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
        }
    }

    for (int i = -1; i < h+1; i++) {
        for (int j = -1; j < w+1; j++) {
            if (i == -1 || j == -1 || i == h || j == w) cout << '#';
            else cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}
}