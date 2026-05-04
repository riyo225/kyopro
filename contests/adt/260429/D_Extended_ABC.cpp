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

template <typename T>
struct RLE {
    using V = typename T::value_type;

    struct Node { V val; ll len; };

    vector<Node> blocks;
    vector<ll> prefix_len;

    RLE(const T& s) {
        prefix_len.push_back(0);
        for (ll l = 0, n = s.size(); l < n; ) {
            ll r = l + 1;
            while (r < n && s[l] == s[r]) r++;
            blocks.push_back({s[l], r - l});
            prefix_len.push_back(prefix_len.back() + (r - l));
            l = r;
        }
    }

    auto begin() const { return blocks.begin(); }
    auto end() const { return blocks.end(); }

    T decode() const {
        T res;
        res.reserve(prefix_len.back());
        for (const auto& [val, len] : blocks) {
            for (int i = 0; i < len; i++) res.push_back(val);
        }
        return res;
    }

    V get_val_at(ll k) const {
        assert(0 <= k && k < prefix_len.back());

        auto it = upper_bound(all(prefix_len), k);
        ll idx = distance(prefix_len.begin(), prev(it));

        return blocks[idx].val;
    }
};


int main() {
    setup_fast_io();

    string s; cin >> s;

    RLE<string> rle(s);

    bool ans = true;
    if (rle.blocks.size() > 3) ans = false;
    else if (rle.blocks.size() == 3) {
        rep(i, 3) {
            char c = 'A' + i;
            if (rle.blocks[i].val != c) ans = false; 
        }
    }
    else if (rle.blocks.size() == 2) {
        if (rle.blocks[0].val > rle.blocks[1].val) ans = false;
    }

    yes(ans);


    return 0;
}