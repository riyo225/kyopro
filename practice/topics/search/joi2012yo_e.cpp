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
const ll dx[6] = {1, 0, -1, 0, -1, 1};
const ll dy[6] = {0, 1, 0, -1, -1, -1};
const ll dh[6] = {1, 0, -1, 0, 1, -1};
const ll dw[6] = {0, 1, 0, -1, 1, 1};
struct Edge
{
    ll to;
    ll cost;
};
using Graph = vector<vector<ll>>;


int main() {
    ll H, W;
    cin >> W >> H;

    vector<vector<ll>> vec(H, vector<ll> (W));
    rep(i, H) {
        rep(j, W) {
            cin >> vec[i][j];
        }
    }

    vector<vector<ll>> cnt(H, vector<ll> (W, 6));

    rep(i, H) {
        rep(j, W) {
            if (vec[i][j] == 1) {
                if (i % 2 == 1) {
                    rep(k, 6) {
                        ll nh = i + dx[k];
                        ll nw = j + dy[k];

                        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;

                        cnt[nh][nw]--;
                    }
                }
                else {
                    rep(k, 6) {
                        ll nh = i + dh[k];
                        ll nw = j + dw[k];

                        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;

                        cnt[nh][nw]--;
                    }
                }
            }
        }
    }

    rep(i, H) {
        rep(j, W) {
            if (cnt[i][j] == 0) {
                if (i % 2 == 1) {
                    rep(k, 6) {
                        ll nh = i + dx[k];
                        ll nw = j + dy[k];

                        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;

                        cnt[nh][nw]--;
                    }
                }
                else {
                    rep(k, 6) {
                        ll nh = i + dh[k];
                        ll nw = j + dw[k];

                        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;

                        cnt[nh][nw]--;
                    }
                }
            }
        }
    }

    rep(i, H) {
        rep(j, W) {
            cout << cnt[i][j] << " ";
        }
        cout << nl;
    }

    ll ans = 0;
    rep(i, H) {
        rep(j, W) {
            if (vec[i][j] != 1) continue;
            ans += cnt[i][j];
        }
    }    

    cout << ans << nl;
    return 0;
}