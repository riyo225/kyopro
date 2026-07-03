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
    #define debug_all(v) { cerr << #v << ": { "; for(auto&& e : v) cerr << e << " "; cerr << "}" << endl; }
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

// 前計算 O(NloglogN)
// 素因数分解 O(logN)
struct SPF {
    vector<ll> spf;

    SPF(ll n) : spf(n + 1) {
        for (ll i = 0; i <= n; i++) spf[i] = i;
        for (ll i = 2; i * i <= n; i++) {
            if (spf[i] == i) {
                for (ll j = i * i; j <= n; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
    }

    bool is_prime(ll x) {
        if (x <= 1) return false;
        return spf[x] == x;
    }

    map<ll, ll> factorize(ll x) {
        map<ll, ll> res;
        while (x > 1) {
            res[spf[x]]++;
            x /= spf[x];
        }
        return res;
    }
};


int main() {
    setup_fast_io();

    ll n, m; cin >> n >> m;
    vll a(n); cin >> a;

    SPF spf(100000);
    set<ll> st;
    vector<bool> ans(m+1, true);
    rep(i, n) {
        for (auto [k, v] : spf.factorize(a[i])) {
            st.insert(k);
        }
    }

    for (ll x : st) {
        for (int i = 1; i * x <= m; i++) {
            ans[i * x] = false; 
        }
    }

    vll res;
    for (int i = 1; i <= m; i++) {
        if (ans[i]) res.push_back(i);
    }
    cout << res.size() << nl;
    for (ll x : res) {
        cout << x << nl;
    }

    return 0;
}