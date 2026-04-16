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

#define DEBUG
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

// compressの引数の配列は圧縮される
// 返り値はソート&重複削除済み配列
template<typename T>
vector<T> compress(vector<T> &X) {
    vector<T> vals = X;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < (int)(X.size()); i++) {
        X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
    }
    return vals;
}

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

struct Q {
    int type;
    ll a, b;
};

int main() {
    setup_fast_io();

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    vector<ll> vec;
    rep(i, n) {
        cin >> a[i];
        vec.push_back(a[i]);
    }

    
    vector<Q> query(q);
    rep(i, q) {
        cin >> query[i].type >> query[i].a >> query[i].b;
        if (query[i].type == 1) {
            query[i].a--;
            vec.push_back(query[i].b);
        }
        else {
            vec.push_back(query[i].a);
            vec.push_back(query[i].b);
        }
    }

    vector<ll> vals = compress(vec);
    debug_vec(vec);
    debug_vec(vals);

    FenwickTree<ll> cnt_ft(vals.size());
    FenwickTree<ll> sum_ft(vals.size());
    
    rep(i, n) {
        int idx = vec[i];
        cnt_ft.add(idx, 1);
        sum_ft.add(idx, a[i]);
    }

    for (int i = 0; i < vals.size(); i++) {
        cout << i << " ";
        debug(cnt_ft.get(i));
    }
    for (int i = 0; i < vals.size(); i++) {
        cout << i << " ";
        debug(sum_ft.query(i));
    }

    rep(i, q) {
        if (query[i].type == 1) {
            int x = query[i].a;
            ll y = query[i].b;

            int old_idx = lower_bound(all(vals), a[x]) - vals.begin();
            cnt_ft.add(old_idx, -1);
            sum_ft.add(old_idx, -a[x]);

            a[x] = y;
            int new_idx = lower_bound(all(vals), y) - vals.begin();
            cnt_ft.add(new_idx, 1);
            sum_ft.add(new_idx, y);
        }
        else {
            ll l = query[i].a;
            ll r = query[i].b;

            if (l > r) {
                cout << n * l << nl;
                continue;
            }

            int il = lower_bound(all(vals), l) - vals.begin();
            int ir = upper_bound(all(vals), r) - vals.begin();

            ll res1 = cnt_ft.query(il) * l;
            ll res2 = sum_ft.range_query(il, ir);
            ll res3 = (n - cnt_ft.query(ir)) * r;
            cout << res1 + res2 + res3 << nl;
        }
    }

    return 0;
}