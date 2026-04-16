#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define each(x, a) for (auto& x : a)
#define each2(a, b, c) for (auto& [a, b] : c)
#define repbit(bit, n) for (int bit = 0; bit < (1<<(int)n); bit++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) ((int)(x).size())
const string alpha = "abcdefghijklmnopqrstuvwxyz";
const string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr ll INF = (1LL << 60);
constexpr int INT_INF = (1 << 30);
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
using Graph = vector<vector<int>>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(m);
    vector<char> c(m);
    rep(i, m) {
        cin >> s[i] >> c[i];
        s[i]--;
    }

    int l;
    if (n == 1) {
        l = 0;
    }
    else {
        l = pow(10, n-1);
    }
    for (int i = l; i < pow(10, n); i++) {
        string t = to_string(i);
        bool f = true;
        rep(j, m) {
            if (t[s[j]] != c[j]) f = false;
        }
        if (f) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}