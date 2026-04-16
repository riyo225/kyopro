#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF_INT = 2e9;
const ll INF_LL = 9e18;
const int MOD = 1000000007; // 998244353
const double PI = acos(-1);
// const string ALPHA_LOWER = "abcdefghijklmnopqrstuvwxyz"; // 必要ならコメント解除
// const string ALPHA_UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // 必要ならコメント解除
const int DX8[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int DY8[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int DX4[] = {1, 0, -1, 0};
const int DY4[] = {0, 1, 0, -1};
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

// デバッグ出力を有効にするには、以下の行のコメントアウトを解除してください。
// #define DEBUG
#ifdef DEBUG
    #define debug(x) cerr << #x << ": " << (x) << endl
    #define debug_vec(vec) { cerr << #vec << ": "; for(const auto& elem : vec) cerr << elem << " "; cerr << endl; }
    #define debug_pair(p) cerr << #p << ": (" << (p).first << ", " << (p).second << ")" << endl
    #define debug_2d_vec(vec2d) { cerr << #vec2d << ":" << endl; for(const auto& row : vec2d) { cerr << "  "; for(const auto& elem : row) cerr << elem << " "; cerr << endl; } }
    // mapのデバッグ出力は必要性が低いが、もし使うなら以下を使用
    // #define debug_map(m) { cerr << #m << ": "; for(const auto& [key, val] : m) cerr << "(" << key << ":" << val << ") "; cerr << endl; }
#else
    #define debug(x)
    #define debug_vec(vec)
    #define debug_pair(p)
    #define debug_2d_vec(vec2d)
    // #define debug_map(m)
#endif

void setup_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);
}

struct Edge {
    ll to;
    ll cost;
};
// using Graph = vector<vector<ll>>;
// using Graph = vector<vector<Edge>>;


int main() {
    setup_fast_io();

    ll n;
    cin >> n;
    vector<ll> p(n);
    rep(i, n) {
        cin >> p[i];
    }

    vector<ll> q;
    ll idx, v;
    for (int i = n-1; i >= 1; i--) {
        q.push_back(p[i]);
        if (p[i] < p[i-1]) {
            idx = i-1;
            v = p[i-1];
            break;
        }
    }
    sort(all(q));

    ll tmp = v;
    for (int i = sz(q) - 1; i >= 0; i--) {
        if (q[i] < v) {
            swap(v, q[i]);
            break;
        }
    }
    sort(rall(q));
    
    for (int i = 0; i < n; i++) {
        if (i < idx) {
            cout << p[i] << " ";
        }
        else if (i == idx) {
            cout << v << " ";
        }
    }
    for (auto m : q) {
        cout << m << " ";
    }
    cout << nl;



    return 0;
}