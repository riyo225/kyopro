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
// using Graph = vector<vector<Edge>>;

int main() {
    setup_fast_io();

    ll n;
    cin >> n;
    set<ll> st;

    vector<vector<string>> vec(10); 

    vector<ll> two(27, 1);
    for (int i = 0; i < 26; i++) {
        two[i+1] = two[i] * 2;
    }

    for (int i = 0; i < 26; i++) {
        string s = to_string(two[i]);
        vec[sz(s)].push_back(s);
        st.insert(two[i]);
    }

    for (int i = 2; i < 10; i++) {
        for (int j = 0; j < sz(vec[1]); j++) {
            for (int k = 0; k < sz(vec[i-1]); k++) {
                string t = vec[1][j] + vec[i-1][k];
                string u = vec[i-1][k] + vec[1][j];
                if (t == u) {
                    ll x = stoll(t);
                    st.insert(x);
                    vec[i].push_back(t);
                }
                else {
                    ll x = stoll(t);
                    ll y = stoll(u);
                    st.insert(x);
                    vec[i].push_back(t);
                    st.insert(y);
                    vec[i].push_back(u);
                }
            }
        }
    }


    auto it = st.begin();
    advance(it, n-1);
    cout << *it << nl;
    return 0;
}