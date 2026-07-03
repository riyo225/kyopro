#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
using vll = vector<ll>;
using vvll = vector<vll>;
using Graph = vvll;
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (T& x : v) is >> x; return is; }
template <typename T> using min_pq = priority_queue<T, vector<T>, greater<T>>;
const ll INF = 2e18;
// const ll MOD = 998244353;
// const ll MOD = 1000000007;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define rrep(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(x) ((ll)(x).size())
#define nl "\n"
#define pcnt(n) __builtin_popcountll(ll(n))
#define yes(ans) cout << ((ans) ? "Yes" : "No") << nl;
#define YES(ans) cout << ((ans) ? "YES" : "NO") << nl;
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }

// #define DEBUG
#ifdef DEBUG
    template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) { return os << "(" << p.first << ", " << p.second << ")"; }
    #define debug(x) cerr << #x << ": " << (x) << endl
    #define debug_all(v) { cerr << #v << ": { "; for(auto& e : v) cerr << e << " "; cerr << "}" << endl; }
    #define debug_2d(v) { cerr << #v << ":" << endl; for(auto& r : v) { cerr << "  "; for(auto& e : r) cerr << e << " "; cerr << endl; } }
#else
    #define debug(x)
    #define debug_all(v)
    #define debug_2d(v)
#endif

void setup_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(15);
}

// Compressor<type> comp;
template <typename T>
struct Compressor {
    vector<T> vals;

    Compressor(const vector<T>& a) {
        vals = a;
        sort(all(vals));
        vals.erase(unique(all(vals)), vals.end());
    }

    // 元の値 -> 圧縮後の座標
    ll get(const T& x) const {
        return lower_bound(all(vals), x) - vals.begin();
    }

    vector<ll> get_compressed(const vector<T>& a) const {
        vector<ll> res(a.size());
        for (ll i = 0; i < a.size(); i++) res[i] = get(a[i]);
        return res;
    }

    // 圧縮後の座標 -> 元の値
    T inv(ll i) const { return vals[i]; }

    ll size() const { return vals.size(); }
};


int main() {
    setup_fast_io();

    ll n, m, sx, sy; cin >> n >> m >> sx >> sy;
    vll x(n), y(n);
    rep(i, n) {
        cin >> x[i] >> y[i];
    }
    vector<char> d(m);
    vll c(m);
    rep(i, m) {
        cin >> d[i] >> c[i];
    }

    map<ll, set<ll>> mx, my;
    rep(i, n) {
        mx[x[i]].insert(y[i]);
        my[y[i]].insert(x[i]);
    }

    ll ans = 0;
    
    rep(i, m) {
        ll nx = sx, ny = sy;
        if (d[i] == 'U') {
            ny += c[i];
            ll l = min(sy, ny);
            ll r = max(sy, ny);
            auto itr = mx[nx].upper_bound(r);
            auto itl = mx[nx].lower_bound(l);
            ans += distance(itl, itr);
            for (auto it = itl; it != itr; it++) {
                my[*it].erase(nx);
            }
            mx[nx].erase(itl, itr);
        }
        else if (d[i] == 'D') {
            ny -= c[i];
            ll l = min(sy, ny);
            ll r = max(sy, ny);
            auto itr = mx[nx].upper_bound(r);
            auto itl = mx[nx].lower_bound(l);
            ans += distance(itl, itr);
            for (auto it = itl; it != itr; it++) {
                my[*it].erase(nx);
            }
            mx[nx].erase(itl, itr);
        }
        else if (d[i] == 'R') {
            nx += c[i];
            ll l = min(sx, nx);
            ll r = max(sx, nx);
            auto itr = my[ny].upper_bound(r);
            auto itl = my[ny].lower_bound(l);
            ans += distance(itl, itr);
            for (auto it = itl; it != itr; it++) {
                mx[*it].erase(ny);
            }
            my[ny].erase(itl, itr);
        }
        else {
            nx -= c[i];
            ll l = min(sx, nx);
            ll r = max(sx, nx);
            auto itr = my[ny].upper_bound(r);
            auto itl = my[ny].lower_bound(l);
            ans += distance(itl, itr);
            for (auto it = itl; it != itr; it++) {
                mx[*it].erase(ny);
            }
            my[ny].erase(itl, itr);
        }

        sx = nx, sy = ny;
    }
    cout << sx << " " << sy << " " << ans << nl;

    return 0;
}