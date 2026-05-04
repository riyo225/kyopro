// [prefix: geom, sankakukansuu]

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