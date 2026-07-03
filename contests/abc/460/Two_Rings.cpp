#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
using vll = vector<ll>;
using vvll = vector<vll>;
using Graph = vvll;
template<typename T> istream& operator>>(istream& is, vector<T>& v) { for (T& x : v) is >> x; return is; }
template <typename T> using min_pq = priority_queue<T, vector<T>, greater<T>>;
const ll INF = 2e18;
// const ll MOD = 998244353;
// const ll MOD = 1000000007;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define rrep(i, n) for (ll i = (ll)(n) - 1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(x) ((ll)(x).size())
#define nl "\n"
#define pcnt(n) __builtin_popcountll(ll(n))
#define yes(ans) cout << ((ans) ? "Yes" : "No") << nl;
#define YES(ans) cout << ((ans) ? "YES" : "NO") << nl;
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }

// #define DEBUG
#ifdef DEBUG
    template<typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) { return os << "(" << p.first << ", " << p.second << ")"; }
    #define debug(x) cerr << #x << ": " << (x) << endl
    #define debug_all(v) { cerr << #v << ": { "; for(auto& e : v) cerr << e << " "; cerr << "}" << endl; }
    #define debug_2d(v) { cerr << #v << ":" << endl; for(auto& r : v) { cerr << "  "; for(auto& e : r) cerr << e << " "; cerr << endl; } }
#else
    #define debug(x)
    #define debug_all(v)
    #define debug_2d(v)
#endif

void setup_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(15);
}

const ld PI = acosl(-1.0L);
const ld EPS = 1e-10;

template <typename T>
struct Point {
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}

    template <typename U>
    Point(const Point<U>& p) : x(p.x), y(p.y) {}

    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator*(T k) const { return Point(x * k, y * k); }
    Point operator/(T k) const { return Point(x / k, y / k); }
};

using ptll = Point<ll>;
using ptld = Point<ld>;

// 内積と外積
template <typename T>
inline T dot(Point<T> a, Point<T> b) { return a.x * b.x + a.y * b.y; }
template <typename T>
inline T cross(Point<T> a, Point<T> b) { return a.x * b.y - a.y * b.x; }

inline ld deg2rad(ld deg) { return deg * PI / 180.0L; }
inline ld rad2deg(ld rad) { return rad * 180.0L / PI; }

// 角度を [ 0, 2PI ) の範囲に正規化
inline ld norm_angle(ld rad) {
    ld res = fmodl(rad, 2.0L * PI);
    if (res < 0) res += 2.0L * PI;
    return res;
}

// 角度を取得する [ -PI, PI ] 
inline ld get_angle(ptld p) {
    return atan2l(p.y, p.x);
}

// (x, y) を反時計周りに角度 rad 回転
ptld rotate(ptld p, ld rad) {
    return ptld(p.x * cosl(rad) - p.y * sinl(rad), p.x * sinl(rad) + p.y * cosl(rad));
}

inline ld get_dist(ptld a, ptld b) {
    return hypotl(a.x - b.x, a.y - b.y);
}

//  1: a-b に対して c が左
// -1: a-b に対して c が右
//  0: 直線
int ccw(ptld a, ptld b, ptld c) {
    ptld ba = b - a;
    ptld ca = c - a;
    ld cp = cross(ba, ca);
    if (cp > EPS) return 1;
    if (cp < -EPS) return -1;
    return 0;
}

// 偏角ソート (完全整数・誤差なし)
auto angular_cmp = [](const ptll& a, const ptll& b) {
    auto half = [](const ptll& p) {
        if (p.y > 0 || (p.y == 0 && p.x > 0)) return 0;
        return 1;
    };
    
    ll ha = half(a), hb = half(b);
    if (ha != hb) return ha < hb;

    ll cp = cross(a, b);
    if (cp != 0) return cp > 0;
    return dot(a, a) < dot(b, b);
};

int main() {
    setup_fast_io();

    ll t; cin >> t;
    while (t--) {
        ld x1, y1, r1, x2, y2, r2; cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        ld dis = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        dis = sqrt(dis);
        ld r = min(r1, r2);
        ld R = max(r1, r2);
        yes(r1 + r2 >= dis && (r + dis) >= R);
    }

    return 0;
}