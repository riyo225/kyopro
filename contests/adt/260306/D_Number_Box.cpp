#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
const int INF_INT = 2e9;
const ll INF_LL = 2e18;
const int MOD = 998244353;
// const int MOD = 1000000007;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define rrep(i, n) for (ll i = (ll)(n)-1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(x) ((ll)(x).size())
#define nl "\n"
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << nl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << nl;
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }

// #define DEBUG
#ifdef DEBUG
    #define debug(x) cerr << #x << ": " << (x) << endl
    #define debug_vec(vec) { cerr << #vec << ": "; for(const auto& elem : vec) cerr << elem << " "; cerr << endl; }
    #define debug_pair(p) cerr << #p << ": (" << (p).first << ", " << (p).second << ")" << endl
    #define debug_2d_vec(vec2d) { cerr << #vec2d << ":" << endl; for(const auto& row : vec2d) { cerr << "  "; for(const auto& elem : row) cerr << elem << " "; cerr << endl; } }
    #define debug_map(m) { cerr << #m << ": "; for(const auto& [key, val] : m) cerr << "(" << key << ":" << val << ") "; cerr << endl; }
#else
    #define debug(x)
    #define debug_vec(vec)
    #define debug_pair(p)
    #define debug_2d_vec(vec2d)
    #define debug_map(m)
#endif

void setup_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(15);
}

// using Graph = vector<vector<ll>>;
// using Graph = vector<vector<Edge>>;

int main() {
    setup_fast_io();

    ll n;
    cin >> n;
    vector<vector<char>> c(n, vector<char> (n));
    vector<vector<ll>> a(n, vector<ll> (n));

    rep(i, n) {
        rep(j, n) {
            cin >> c[i][j];
            a[i][j] = c[i][j] - '0';
        }
    }
    vector<ll> ten(n+1, 1);
    rep(i, n) {
        ten[i+1] = ten[i] * 10;
    }

    ll ans = 0;
    rep(i, n) {
        rep(j, n) {
            ll M = 0;
            rep(k, 8) {
                ll nx = ((i + dx[k]) % n + n) % n;
                ll ny = ((j + dy[k]) % n + n) % n;

                chmax(M, a[nx][ny]);
            }

            vector<ll> dir;
            rep(k, 8) {
                ll nx = ((i + dx[k]) % n + n) % n;
                ll ny = ((j + dy[k]) % n + n) % n;

                if (a[nx][ny] == M) {
                    dir.push_back(k);
                }
            }

            vector<ll> vec;
            vec.push_back(a[i][j]);
            ll x = i;
            ll y = j;
            for (ll k : dir) {
                for (int l = 1; l < n; l++) {
                    ll nx = ((x + dx[k]) % n + n) % n;
                    ll ny = ((y + dy[k]) % n + n) % n;
                    vec.push_back(a[nx][ny]);
                    x = nx;
                    y = ny;
                }
            }

            ll s = 0;
            rrep(l, n) {
                s += vec[l] * ten[n-l-1];
            }
            chmax(ans, s);
        }
    }

    cout << ans << nl;

    return 0;
}