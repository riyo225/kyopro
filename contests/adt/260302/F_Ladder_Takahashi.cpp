#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
const int INF_INT = 2e9;
const ll INF_LL = 2e18;
const int MOD = 998244353;
// const int MOD = 1000000007;
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

using Graph = vector<vector<ll>>;
// using Graph = vector<vector<Edge>>;
// build の引数の配列は圧縮される
// vals は辞書
template<typename T>
struct Compressor {
    vector<T> vals;

    void build(vector<T> &X) {
        vals = X;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        for (int i = 0; i < (int)(X.size()); i++) {
            X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();
        }
    }

    ll zip(T x) {
        return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
    }

    T unzip(ll i) {
        return vals[i];
    }

    ll size() {
        return vals.size();
    }
};

int main() {
    setup_fast_io();

    ll n;
    cin >> n;
    vector<ll> vec;
    vector<ll> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
        vec.push_back(a[i]);
        vec.push_back(b[i]);
    }
    vec.push_back(1);
    Compressor<ll> cp;
    cp.build(vec);

    Graph graph(cp.size());
    for (int i = 0; i < 2 * n; i += 2) {
        graph[vec[i]].push_back(vec[i+1]);
        graph[vec[i+1]].push_back(vec[i]);
    }

    for (auto v : graph) {
        debug_vec(v);
    }

    vector<bool> seen(cp.size(), false);
    queue<ll> que;

    seen[0] = true;
    que.push(0);

    while (!que.empty()) {
        ll v = que.front();
        que.pop();

        for (ll nv : graph[v]) {
            if (seen[nv] != false) continue;

            seen[nv] = true;
            que.push(nv);
        }
    }

    debug_vec(seen);

    debug_vec(vec);
    debug_vec(cp.vals);
    ll ans = 0;
    for (int i = 0; i < cp.size(); i++) {
        if (seen[i] != false) chmax(ans, cp.unzip(i));
    }

    cout << ans << nl;


    return 0;
}