#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF_INT = 2e9;
const ll INF_LL = 2e18;
const int MOD = 998244353;
// const int MOD = 1000000007;
const double PI = acos(-1);
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
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

template <typename T>
struct FenwickTree {
    ll n;
    vector<T> tree;

    FenwickTree(ll n) : n(n), tree(n + 1, 0) {}

    void build(const vector<T>& v) {
        for (int i = 0; i < n; i++) tree[i+1] = v[i];
        for (int i = 1; i <= n; i++) {
            int j = i + (i & -i);
            if (j <= n) tree[j] += tree[i];
        }
    }

    void add(ll i, T x) {
        for (i++; i <= n; i += (i & -i)) tree[i] += x;
    }

    void update(ll i, T x) {
        add(i, x - get(i));
    }

    T query(ll i) {
        T s = 0;
        for (; i > 0; i -= i & -i) s += tree[i];
        return s;
    }

    T range_query(ll l, ll r) {
        if (l >= r) return 0;
        return query(r) - query(l);
    }

    T get(ll i) {
        return query(i+1) - query(i);
    }
};

int main() {
    setup_fast_io();

    ll n, q;
    cin >> n >> q;

    FenwickTree<ll> ft(n);
    vector<ll> s(n);
    rep(i, n) cin >> s[i];
    ft.build(s);

    while (q > 0) {
        ll type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            l--;
            cout << ft.range_query(l, r) << nl;
        }
        else {
            l--;
            ft.update(l, r);
        }
        q--;
    }


    return 0;
}