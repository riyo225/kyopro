// [prefix: sankakukansuu]

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