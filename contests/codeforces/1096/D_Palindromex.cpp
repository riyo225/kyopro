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

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vll a(2 * n); cin >> a;
        vll idx;
        rep(i, 2*n) {
            if (a[i] == 0) idx.push_back(i);
        }
        ll ans = 1;

        rep(j, 2) {
            ll i = 1;
            ll c = idx[j];
            vector<bool> seen(n+1, false);
            seen[0] = true;
            while (c+i < n*2 && c-i >= 0) {
                if (a[c+i] == a[c-i]) {
                    seen[a[c+i]] = true;
                    i++;
                }
                else break;
            }

            rep(k, n+1) {
                if (!seen[k]) {
                    chmax(ans, k);
                    break;
                }
            }
        }

        ll l = idx[0];
        ll r = idx[1];

        bool flag = true;
        vector<bool> seen(n+1, false);
        seen[0] = true;
        ll i = 1;
        while (r-i >= 0 && l+i < 2*n) {
            if (a[l+i] == a[r-i]) {
                seen[a[l+i]] = true;
                i++;
            }
            else {
                if (r-i > l+i) {
                    flag = false;
                }
                break;
            }
        }

        if (flag) {
            rep(k, n+1) {
                if (!seen[k]) {
                    chmax(ans, k);
                    break;
                }
            }
        }
        cout << ans << nl;
    }

    return 0;
}