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
#define DEBUG
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

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vector<pair<int, int>> vec;

    for (int i = 0; i < n; i++) {
        int j = 0;
        int count = 0;
        while (i + j < n && a[i] == a[i + j]) {
            count++;
            j++;
        }
        vec.push_back(make_pair(a[i], count));
        i += count - 1;
    }

    // rep(i, sz(vec)) {
    //     debug_pair(vec[i]);
    // }

    vector<pair<int, int>> ans_vec;

    for (int i = 0; i < sz(vec); i++) {
        int pi = vec[i].first;
        int pc = vec[i].second;

        pc %= 4;
        if (pc == 0) {
            continue;
        }
        if (ans_vec.empty()) {
            ans_vec.push_back({pi, pc});
        }
        else {
            if (ans_vec.back().first == pi) {
                ans_vec.back().second += pc;
                ans_vec.back().second %= 4;

                if (ans_vec.back().second == 0) {
                    ans_vec.pop_back();
                }
            }
            else {
                ans_vec.push_back({pi, pc});
            }
        }
    }

    int ans = 0;
    rep(i, sz(ans_vec)) {
        ans += ans_vec[i].second;
    }

    cout << ans << nl;
    return 0;
}