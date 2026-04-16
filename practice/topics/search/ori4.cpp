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
#define nl "\n"
const string alpha = "abcdefghijklmnopqrstuvwxyz";
const string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr ll INF = (1LL << 60);
constexpr int INT_INF = (1 << 30);
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
struct Edge
{
    int to;
    ll cost;
};
using Graph = vector<vector<int>>;


int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n));
    rep(i, n) {
        rep(j, n) {
            cin >> a[i][j];
        }
    }

    vector<int> p(n);
    rep(i, n) {
        p[i] = i;
    }

    int ans = INT_INF;
    do {
        int sum = 0;
        for (int i = 0; i < n-1; i++) {
            sum += a[p[i]][p[i+1]];
        }
        ans = min(ans, sum);
    } while (next_permutation(all(p)));
    
    cout << ans << endl;
    return 0;
}