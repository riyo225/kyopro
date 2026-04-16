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
#define rrep(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i)
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
// struct Edge { ll to; ll cost; };
// using Graph = vector<vector<Edge>>;

int main() {
    setup_fast_io();

    ll n; cin >> n;
    string s; cin >> s;
    ll q; cin >> q;
    ll flag = 0;
    vector<ll> t(q), x(q);
    vector<char> c(q);
    rep(i, q) {
        cin >> t[i] >> x[i] >> c[i];
        x[i]--;
    }
    ll idx = -1;
    ll w;
    for (int i = q-1; i >= 0; i--) {
        if (t[i] == 2 || t[i] == 3) {
            idx = i;
            w = t[i];
            break;
        }
    }
    vector<ll> is_change(n, false);
    if (idx == -1) {
        rep(i, q) {
            s[x[i]] = c[i];
        }
    }
    else {
        rep(i, q) {
            if (i < idx) {
                if (t[i] == 1) {
                    s[x[i]] = c[i];
                }
            }
            else {
                if (t[i] == 1) {
                    s[x[i]] = c[i];
                    is_change[x[i]] = true;
                }
            }
        }
    }

    if (idx == -1) {
        cout << s << nl;
    }
    else {
        if (w == 2) {
            rep(i, n) {
                if (is_change[i]) cout << s[i];
                else {
                    char b = tolower(s[i]);
                    cout << b;
                }
            }
        }
        else {
            rep(i, n) {
                if (is_change[i]) cout << s[i];
                else {
                    char b = toupper(s[i]);
                    cout << b;
                }
            }
        }
    }

    return 0;
}