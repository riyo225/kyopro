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
struct BIT {
    ll n;
    vector<T> tree;

    BIT(ll n) : n(n), tree(n + 1, 0) {}

    void build(const vector<T>& a) {
        for (ll i = 0; i < n; i++) tree[i + 1] = a[i];
        for (ll i = 1; i <= n; i++) {
            ll j = i + (i & -i);
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
        return query(i + 1) - query(i);
    }
};

struct Offline2DPointSum {
    struct Point { ll x, y, w; };
    struct Query { ll xl, xr, yd, yu; ll id; };

    vector<Point> points;
    vector<Query> queries;

    void add_point(ll x, ll y, ll w = 1) { points.push_back({x, y, w}); }

    void add_query(ll xl, ll xr, ll yd, ll yu) { queries.push_back({xl, xr, yd, yu, (ll)queries.size()}); }

    vector<ll> solve() {
        // 座標圧縮
        vector<ll> ys;
        for (const auto& p : points) ys.push_back(p.y);
        for (const auto& q : queries) {
            ys.push_back(q.yd);
            ys.push_back(q.yu);
        }
        sort(all(ys));
        ys.erase(unique(all(ys)), ys.end());

        auto get_y = [&](ll y) -> ll {
            return lower_bound(all(ys), y) - ys.begin();
        };

        struct Event {
            ll x;
            ll type; // 0: 点, 1: クエリの端
            ll yd, yu, sign;
            ll w;
            ll id;
            bool operator<(const Event& o) const {
                if (x != o.x) return x < o.x;
                return type < o.type;
            }
        };

        vector<Event> events;
        for (const auto& p : points) {
            events.push_back({p.x, 0, get_y(p.y), -1, 1, p.w, -1});
        }
        for (const auto& q : queries) {
            events.push_back({q.xr, 1, get_y(q.yd), get_y(q.yu), 1, 0, q.id});
            events.push_back({q.xl - 1, 1, get_y(q.yd), get_y(q.yu), -1, 0, q.id});
        }

        sort(all(events));
        BIT<ll> bit(ys.size() + 5);
        vector<ll> ans(queries.size(), 0);

        for (const auto& e : events) {
            if (e.type == 0) {
                bit.add(e.yd, e.w);
            }
            else {
                ll sum = bit.range_query(e.yd, e.yu + 1);
                ans[e.id] += sum * e.sign;
            }
        }
        return ans;
    }
};

int main() {
    setup_fast_io();

    ll n, m; cin >> n >> m;
    vll l(m), r(m);
    rep(i, m) {
        cin >> l[i] >> r[i];
    }
    ll q; cin >> q;
    vll s(q), t(q);
    rep(i, q) {
        cin >> s[i] >> t[i];
    }

    map<ll, set<ll>> mpl, mpr;
    rep(i, m) {
        mpl[l[i]].insert(r[i]);
        mpr[r[i]].insert(l[i]);
    }

    Offline2DPointSum sweep;
    rep(i, m) {
        sweep.add_point(l[i], r[i]);
    }
    rep(i, q) {
        sweep.add_query(s[i], 2e18, 0, t[i]);
    }
    auto res = sweep.solve();

    rep(i, q) {
        if (!mpl.count(s[i]) || !mpr.count(t[i])) {
            yes(false);
            continue;
        }

        auto itl = mpl[s[i]].upper_bound(t[i]);
        auto itr = mpr[t[i]].lower_bound(s[i]);

        if (itl == mpl[s[i]].begin()) {
            yes(false);
            continue;
        }
        itl--;

        if (itl == mpl[s[i]].end() || itr == mpr[t[i]].end()) {
            yes(false);
            continue;
        }

        if (*itr > *itl + 1) {
            yes(false);
            continue;
        }
        
        if (*itl == t[i] && *itr == s[i] && res[i] <= 1) {
            yes(false);
            continue;
        }

        yes(true);
    }

    return 0;
}