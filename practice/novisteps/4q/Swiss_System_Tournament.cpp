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


int main() {
    setup_fast_io();

    ll n, m; cin >> n >> m;
    vector<vector<char>> a(2*n, vector<char> (m));
    rep(i, 2*n) rep(j, m) {
        cin >> a[i][j];
    }

    vector<ll> vec(n*2);
    iota(all(vec), 0);

    vector<ll> point(2*n, 0);
    rep(i, m) {
        for (int j = 0; j < n; j++) {
            if (a[vec[2*j]][i] == 'G' && a[vec[2*j+1]][i] == 'C') {
                point[vec[2*j]]++;
            } 
            if (a[vec[2*j]][i] == 'C' && a[vec[2*j+1]][i] == 'P') {
                point[vec[2*j]]++;
            } 
            if (a[vec[2*j]][i] == 'P' && a[vec[2*j+1]][i] == 'G') {
                point[vec[2*j]]++;
            }
            if (a[vec[2*j]][i] == 'C' && a[vec[2*j+1]][i] == 'G') {
                point[vec[2*j+1]]++;
            } 
            if (a[vec[2*j]][i] == 'P' && a[vec[2*j+1]][i] == 'C') {
                point[vec[2*j+1]]++;
            } 
            if (a[vec[2*j]][i] == 'G' && a[vec[2*j+1]][i] == 'P') {
                point[vec[2*j+1]]++;
            } 
        }
        sort(all(vec), [&](ll x, ll y) {
            if (point[x] == point[y]) return x < y;
            return point[x] > point[y];
        });
    }

    rep(i, 2*n) {
        cout << vec[i]+1 << nl;
    }

    return 0;
}