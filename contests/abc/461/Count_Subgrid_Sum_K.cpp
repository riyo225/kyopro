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

struct CumSum2D {
    ll h, w;
    vector<vector<ll>> s;

    CumSum2D(const vector<vector<ll>>& a) {
        if (a.empty()) return;
        h = a.size(); w = a[0].size();

        s.assign(h + 1, vector<ll> (w + 1, 0));

        for (ll i = 0; i < h; i++) {
            for (ll j = 0; j < w; j++) {
                s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + a[i][j];
            }
        }
    }

    ll query(ll x1, ll y1, ll x2, ll y2) {
        if (x1 >= x2 || y1 >= y2) return 0;
        return s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1];
    }
};

int main() {
    setup_fast_io();

    ll h, w, k; cin >> h >> w >> k;
    vector<vector<ll>> vec(h, vector<ll> (w));
    rep(i, h) {
        string s; cin >> s;
        rep(j, w) {
            if (s[j] == '0') vec[i][j] = 0;
            else vec[i][j] = 1;
        }
    }

    CumSum2D cs(vec);

    ll ans = 0;
    for (int r1 = 1; r1 <= h; r1++) {
        for (int r2 = r1; r2 <= h; r2++) {
            vector<ll> v(w+1, 0);
            rep(i, w+1) {
                v[i] = cs.query(r1-1, 0, r2, i);
            }
            map<ll, ll> count;
            rep(i, w+1) {
                if (count.count(v[i]-k)) ans += count[v[i]-k];
                count[v[i]]++;
            }
        }
    }
    cout << ans << nl;

    return 0;
}