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

struct Point {
    ld x, y;
    Point(ld x = 0, ld y = 0) : x(x), y(y) {}
    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
    Point operator*(ld k) const { return Point(x * k, y * k); }
    Point operator/(ld k) const { return Point(x / k, y / k); }
};

const Point O = {0, 0};

inline ld deg2rad(ld deg) { return deg * PI / 180.0L; }
inline ld rad2deg(ld rad) { return rad * 180.0L / PI; }

// 角度を [ 0, 2PI ) の範囲に正規化
inline ld norm_angle(ld rad) {
    ld res = fmodl(rad, 2.0L * PI);
    if (res < 0) res += 2.0L * PI;
    return res;
}

// 角度を取得する [ -PI, PI ] 
inline ld get_angle(Point p) {
    return atan2l(p.y, p.x);
}

// (x, y) を反時計周りに角度 rad 回転
Point rotate(Point p, ld rad) {
    return Point(p.x * cosl(rad) - p.y * sinl(rad), p.x * sinl(rad) + p.y * cosl(rad));
}

inline ld get_dist(Point a, Point b) {
    return hypotl(a.x - b.x, a.y - b.y);
}

// 内積
inline ld dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

// 外積
inline ld cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

//  1: a-b に対して c が左
// -1: a-b に対して c が右
//  0: 直線
int ccw(Point a, Point b, Point c) {
    Point ba = b - a;
    Point ca = c - a;
    ld cp = cross(ba, ca);
    if (cp > EPS) return 1;
    if (cp < -EPS) return -1;
    return 0;
}

// 偏角ソート
auto angular_cmp = [](const Point& a, const Point& b) {
    ld ang_a = norm_angle(get_angle(a));
    ld ang_b = norm_angle(get_angle(b));
    if (abs(ang_a - ang_b) > EPS) return ang_a < ang_b;
    return dot(a, a) < dot(b, b);
};


int main() {
    setup_fast_io();

    ll n, k; cin >> n >> k;
    vll a(k); cin >> a;
    rep(i, k) {
        a[i]--;
    }

    vector<Point> vec(n);
    rep(i, n) {
        cin >> vec[i].x >> vec[i].y;
    }

    vector<ld> min_dist(n, INF);
    rep(i, k) {
        min_dist[a[i]] = 0;
    }

    rep(i, n) {
        if (min_dist[i] != 0) {
            rep(j, k) {
                chmin(min_dist[i], get_dist(vec[i], vec[a[j]]));
            }
        }
    }

    ld ans = 0;
    rep(i, n) {
        if (min_dist[i] != INF) {
            chmax(ans, min_dist[i]);
        }
    }
    cout << ans << nl;


    return 0;
}