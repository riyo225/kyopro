// --- 1. 標準ヘッダ ---
#include <bits/stdc++.h> // 全ての標準ライブラリをまとめてインクルードする場合 (非推奨)

// --- 2. 名前空間 ---
using namespace std;

// --- 3. 型エイリアス ---
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// --- 4. 定数 ---
const int INF_INT = 2e9;
const ll INF_LL = 9e18;
const int MOD = 1000000007; // または 998244353
const double PI = acos(-1);
// const string ALPHA_LOWER = "abcdefghijklmnopqrstuvwxyz"; // 必要ならコメント解除
// const string ALPHA_UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // 必要ならコメント解除

// グリッド問題用の方向配列 (8方向)
const int DX8[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int DY8[] = {0, 1, 0, -1, 1, -1, 1, -1};
// グリッド問題用の方向配列 (4方向)
const int DX4[] = {1, 0, -1, 0};
const int DY4[] = {0, 1, 0, -1};

// --- 5. マクロ ---
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define rrep(i, n) for (ll i = (ll)(n)-1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(x) ((ll)(x).size())
#define nl "\n"
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << nl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << nl;

// --- 6. 便利関数 (テンプレート) ---
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }

// --- 7. デバッグマクロ (条件付きコンパイル) ---
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

// --- 8. 高速I/O設定 ---
void setup_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL); // 基本的に不要だが、稀に効果あり
}

// --- 9. よく使う構造体/クラス/グローバル変数 (任意) ---
struct Edge {
    ll to;
    ll cost;
};
// using Graph = vector<vector<ll>>; // 重みなしグラフ
using Graph = vector<vector<Edge>>; // 重み付きグラフ



int main() {
    setup_fast_io();

    // ここに問題の解法を記述

    ll n, m;
    cin >> n >> m;

    Graph graph(n);

    rep(i, m) {
        ll a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        graph[a].push_back({b, w});
    }



    return 0;
}