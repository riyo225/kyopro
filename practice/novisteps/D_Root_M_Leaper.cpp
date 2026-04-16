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

// using Graph = vector<vector<ll>>;
// using Graph = vector<vector<Edge>>;

const ld PI = acosl(-1.0L);
const pld O = {0.0L, 0.0L};

inline ld deg2rad(ld deg) { return deg * PI / 180.0L; }
inline ld rad2deg(ld rad) { return rad * 180.0L / PI; }

// 角度を [ 0, 2PI ) の範囲に正規化
inline ld norm_angle(ld rad) {
    ld res = fmodl(rad, 2.0L * PI);
    if (res < 0) res += 2.0L * PI;
    return res;
}

// 角度を取得する [ -PI, PI ] 
inline ld get_angle(pld a) {
    return atan2l(a.second, a.first);
}

// (x, y) を反時計周りに角度 rad 回転
pair<ld, ld> rotate(pld a, ld rad) {
    return {a.first * cosl(rad) - a.second * sinl(rad), a.first * sinl(rad) + a.second * cosl(rad)};
}

inline ld get_dist(pld a, pld b) {
    return ((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

// 内積
inline ld dot(pld a, pld b) {
    return a.first * b.first + a.second * b.second;
}

// 外積
inline ld cross(pld a, pld b) {
    return a.first * b.second - a.second * b.first;
}

//  1: a-b に対して c が左
// -1: a-b に対して c が右
//  0: 直線
int ccw(pld a, pld b, pld c) {
    pld ba = {b.first - a.first, b.second - a.second};
    pld ca = {c.first - a.first, c.second - a.second};
    ld cp = cross(ba, ca);
    if (cp > 1e-15) return 1;
    if (cp < -1e15) return -1;
    return 0;
}

auto angular_cmp = [](const pair<ld, ld>& a, const pair<ld, ld>& b) {
    ld ang_a = norm_angle(get_angle(a));
    ld ang_b = norm_angle(get_angle(b));
    if (abs(ang_a - ang_b) > 1e-15) {
        return ang_a < ang_b;
    }
    return get_dist(a, O) < get_dist(b, O);
};

int main() {
    setup_fast_io();

    ll n, m;
    cin >> n >> m;

    ll h = n;
    ll w = n;
    vector<vector<ll>> dist(h, vector<ll> (w, -1));
    queue<pll> que;
    
    dist[0][0] = 0;
    que.push({0, 0});
    
    while (!que.empty()) {
        ll x = que.front().first;
        ll y = que.front().second;
        pll v = que.front();
        que.pop();
    
        rep(i, h) {
            rep(j, w) {
                pll nv = {i, j};
                if (v == nv || dist[i][j] != -1) continue;
                if (get_dist(v, nv) == m) {
                    dist[i][j] = dist[x][y] + 1;
                    que.push(nv);
                }
            }
        }
    }

    rep(i, h) {
        rep(j, w) {
            cout << dist[i][j] << " ";
        }
        cout << nl;
    }

    return 0;
}