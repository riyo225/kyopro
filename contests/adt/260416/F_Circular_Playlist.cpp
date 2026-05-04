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

struct CumSum {
    ll n;
    vector<ll> pref, suff;
    
    CumSum(const vector<ll>& a) {
        n = a.size();
        // pref[i] は a[i] を含まない
        // suff[i] は a[i] を含む
        pref.assign(n + 1, 0);
        suff.assign(n + 1, 0);

        // pref[i] = a[0] + ... + a[i-1] : [0, i)
        for (ll i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        // suff[i] = a[i] + ... + a[n-1] : [i, n)
        for (ll i = n - 1; i >= 0; i--) {
            suff[i] = suff[i + 1] + a[i];
        }
    }

    ll sum_except(ll i) {
        return pref[i] + suff[i + 1];
    }

    ll query(ll l, ll r) {
        if (l >= r) return 0;
        return pref[r] - pref[l];
    }

    pair<ll, ll> split_at(ll i) {
        return {pref[i], suff[i]};
    }
};


int main() {
    setup_fast_io();

    ll n, t; cin >> n >> t;
    vll a(n);
    cin >> a;

    CumSum cs(a);

    ll s = cs.pref[n];
    t %= s;

    auto it = upper_bound(all(cs.pref), t);
    it--;
    cout << (it - cs.pref.begin()) + 1 << " " << t - *it << nl;

    return 0;
}