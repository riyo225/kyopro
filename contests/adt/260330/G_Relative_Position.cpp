#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
const int INF_INT = 2e9;
const ll INF_LL = 2e18;
// const int MOD = 998244353;
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
#define popcount(n) __builtin_popcountll(n)
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
    #define debug_vec_pair(vec) { cerr << #vec << ": "; for (const auto& [f, s] : vec) cerr << "(" << f << ", " << s << ") "; cerr << endl; }
#else
    #define debug(x)
    #define debug_vec(vec)
    #define debug_pair(p)
    #define debug_2d_vec(vec2d)
    #define debug_map(m)
    #define debug_vec_pair(vec)
#endif

void setup_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(15);
}

// using Graph = vector<vector<ll>>;
struct Edge {
    ll to;
    ll x; ll y;
};
using Graph = vector<vector<Edge>>;

int main() {
    setup_fast_io();

    ll n, m;
    cin >> n >> m;
    Graph graph(n);

    vector<pll> vec(m), pos(m);
    vector<pll> p(n, {INF_LL, INF_LL});
    rep(i, m) {
        cin >> vec[i].first >> vec[i].second;
        vec[i].first--; vec[i].second--;
        cin >> pos[i].first >> pos[i].second;
        graph[vec[i].first].push_back({vec[i].second, pos[i].first, pos[i].second});
        graph[vec[i].second].push_back({vec[i].first, -pos[i].first, -pos[i].second});
    }

    
    queue<ll> que;
    vector<bool> ans(n, true);

    for (int i = 0; i < n; i++) {
        if (i != 0) break;
        if (p[i].first == INF_LL || p[i].second == INF_LL) {
            p[i].first = 0;
            p[i].second = 0;
            que.push(i);
        }

        while (!que.empty()) {
            ll v = que.front();
            que.pop();

            for (auto e : graph[v]) {
                ll nv = e.to;
                ll dx = e.x;
                ll dy = e.y;

                if (p[nv].first != INF_LL) {
                    if (p[nv].first != p[v].first + dx && p[nv].second != p[v].second + dy) ans[nv] = false;
                }
                else {
                    p[nv].first = p[v].first + dx;
                    p[nv].second = p[v].second + dy;
                    que.push(nv);
                }
            }
        }
    }

    rep(i, n) {
        if (ans[i] && p[i].first != INF_LL) {
            cout << p[i].first << " " << p[i].second << nl;
        }
        else {
            cout << "undecidable" << nl;
        }
    }

    return 0;
}