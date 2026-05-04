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


int main() {

    ll n; cin >> n;
    vll a(n); 
    rep(i, n) {
        cin >> a[i];
    }
    vll b;
    rep(i, n) {
        if (a[i] != 0) {
            b.push_back(a[i]);
        }
    }

    vll ans;

    ll m = sz(b);
    if (m % 2 == 0) {
        for (int i = 0; i < m; i += 2) {
            ans.push_back(-b[i+1]);
            ans.push_back(b[i]);
        }
    }
    else {
        ll x = b[0];
        ll y = b[1];
        ll z = b[2];

        ans.push_back(-y);
        ll t = 1;
        while (x - t * z == 0) {
            t++;
        }
        ans.push_back(x - t * z);
        ans.push_back(t * y);

        for (int i = 3; i < m; i += 2) {
            ans.push_back(-b[i+1]);
            ans.push_back(b[i]);
        }
    }

    ll j = 0;
    if (a[0] == 0) cout << 1;
    else cout << ans[j]; j++;

    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            cout << " " << 1;
        }
        else {
            cout << " " <<  ans[j];
            j++;
        }
    }
    cout << endl;

    return 0;
}