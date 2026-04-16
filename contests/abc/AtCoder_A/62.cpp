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
    int x, y;
    cin >> x >> y;
    char xx, yy;
    vector<int> a = {1, 3, 5, 7, 8, 10, 12};
    vector<int> b = {4, 6, 9, 11};
    vector<int> c = {2};

    bool ans = false;
    rep(i, a.size()) {
        if (a[i] == x) {
            xx = 'A';
        }
        if (a[i] == y) {
            yy = 'A';
        }
    }
    rep(i, b.size()) {
        if (b[i] == x) {
            xx = 'B';
        }
        if (b[i] == y) {
            yy = 'B';
        }
    }
    if (x == 2) xx = 'C';
    if (y == 2) yy = 'C';

    if (xx == yy) ans = true;
    yes_no(ans);
    
    return 0;
}