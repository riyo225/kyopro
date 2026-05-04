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

namespace RLE {
    template <typename V>
    struct Node {
        V val;
        ll start;
        ll len;
    };

    template <typename T>
    auto encode (const T& s) {
        using V = typename T::value_type;
        vector<Node<V>> res;
        ll n = s.size();
        for (ll l = 0; l < n; ) {
            ll r = l + 1;
            while (r < n && s[l] == s[r]) r++;
            res.push_back({s[l], l, r - l});
            l = r;
        }
        return res;
    }

    template <typename T, typename V = typename T::value_type>
    T decode(const vector<Node<V>>& encoded) {
        T res;
        for (const auto& node : encoded) {
            for (ll i = 0; i < node.len; i++) {
                res.push_back(node.val);
            }
        }
        return res;
    }
}


int main() {
    setup_fast_io();

    ll t; cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;

        bool ans = true;

        auto s = RLE::encode(a);
        auto t = RLE::encode(b);

        for (int i = 0; i <= sz(s) - 3; i++) {
            if (s[i].val == '(' && s[i+1].val == 'x' && s[i+1].len == 2  && s[i+2].val == ')') {
                ll min_ = min(s[i].len, s[i+2].len);
                s[i].len -= min_;
                s[i+2].len -= min_;
            }
        }

        for (int i = 0; i <= sz(t) - 3; i++) {
            if (t[i].val == '(' && t[i+1].val == 'x' && t[i+1].len == 2  && t[i+2].val == ')') {
                ll min_ = min(t[i].len, t[i+2].len);
                t[i].len -= min_;
                t[i+2].len -= min_;
            }
        }

        string u = RLE::decode<string>(s);
        string v = RLE::decode<string>(t);

        yes(u == v);
    }

    return 0;
}