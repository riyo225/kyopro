#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define rrep(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define repbit(bit, n) for (ll bit = 0; bit < (1LL << (ll)(n)); bit++)
#define each(x, a) for (auto& x : a)
#define each2(a, b, c) for (auto& [a, b] : c)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) ((ll)(x).size())
#define nl "\n"
template<class T> bool chmax(T& a, const T& b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> bool chmin(T& a, const T& b) {
    if (a > b) { a = b; return true; }
    return false;
}
const string alpha = "abcdefghijklmnopqrstuvwxyz";
const string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr ll INF = (1LL << 60);
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, 1, 0, -1};
struct Edge
{
    ll to;
    ll cost;
};
using Graph = vector<vector<ll>>;


int main() {
    ll H, W, n;
    cin >> H >> W >> n;
    vector<string> field(H);
    rep(i, H) {
        cin >> field[i];
    }
    vector<pair<ll, ll>> st(n+1);
    rep(i, H) {
        rep(j, W) {
            if (field[i][j] == 'S') {
                st[0] = {i, j};
            }
            if (field[i][j] != '.' && field[i][j] != 'X') {
                st[field[i][j] - '0'] = {i, j};
            }
        }
    }

    // each2(a, b ,st) {
    //    cout << a << " " << b << endl; 
    // }

    queue<pair<ll, ll>> que;
    ll ans = 0;

    rep(i, n) {
        que.push(st[i]);
        vector<vector<ll>> dist(H, vector<ll> (W, -1));
        dist[st[i].first][st[i].second] = 0;
        while (!que.empty()) {
            ll h = que.front().first;
            ll w = que.front().second;
            que.pop();

            rep(j, 4) {
                ll nh = h + dx[j];
                ll nw = w + dy[j];
                
                if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
                if (field[nh][nw] == 'X' || dist[nh][nw] != -1) continue;

                dist[nh][nw] = dist[h][w] + 1;

                que.push({nh, nw});
            }
        }
        // rep(i, H) {
        //     rep(j, W) {
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << nl;
        // }
        ans += dist[st[i+1].first][st[i+1].second];
    }

    cout << ans << nl;
    return 0;
}