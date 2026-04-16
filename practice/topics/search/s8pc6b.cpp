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
    vector<ll> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }

    vector<ll> c(n*2);
    rep(i, n) {
        c[i*2] = a[i];
        c[i*2+1] = b[i];
    }


    ll ans = INF;
    rep(i, 2*n-1) {
        for (int j = i+1; j < 2*n; j++) {
            ll sum = 0;
            rep(k, n) {
                sum += min((abs(a[k]-c[i])+abs(b[k]-c[j])), (abs(a[k]-c[j])+abs(b[k]-c[i])));
                sum += abs(a[k]-b[k]);
            }
            // cout << c[i] << " " << c[j] << " " << sum << endl;
            ans = min(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}