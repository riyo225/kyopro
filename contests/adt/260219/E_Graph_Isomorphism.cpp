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

int main() {
    setup_fast_io();

    ll n, m;
    cin >> n >> m;
    vector<vector<bool>> takahashi(n, vector<bool> (n, false));
    vector<vector<bool>> aoki(n, vector<bool> (n, false));

    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        takahashi[a][b] = true;
        takahashi[b][a] = true;
    }

    rep(i, m) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        aoki[a][b] = true;
        aoki[b][a] = true;
    }

    vector<ll> v(n);
    iota(all(v), 0);
    sort(all(v));
    
    bool ans = false;
    do {
        bool flag = true;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (i == j) continue;
                if (takahashi[i][j] == aoki[v[i]][v[j]]) {
                    continue;
                } 
                else {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            ans = true;
        }
    } while (next_permutation(all(v)));

    yes_no(ans);

    return 0;
}