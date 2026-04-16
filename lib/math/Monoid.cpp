// [prefix: monoid]

template <typename T>
struct MonoidMin {
    using Type = T;
    static T op(T a, T b) { return min(a, b); }
    static T e() { return numeric_limits<T>::max() / 2; } 
};

template <typename T>
struct MonoidMax {
    using Type = T;
    static T op(T a, T b) { return max(a, b); }
    static T e() { return numeric_limits<T>::lowest() / 2; } 
};

template <typename T>
struct MonoidSum {
    using Type = T;
    static T op(T a, T b) { return a + b; }
    static T e() { return T(0); } 
};

template <typename T>
struct MonoidXor {
    using Type = T;
    static T op(T a, T b) { return a ^ b; }
    static T e() { return T(0); } 
};

// f(x) = ax + b
struct Affine { ll a, b; };
template <ll MOD = 998244353> struct MonoidAffine {
    using Type = Affine;
    static Type op(Type l, Type r) {
        return { (r.a * l.a) % MOD, (r.a * l.b + r.b) % MOD };
    }
    static Type e() { return {1, 0}; }
};

// これより下わからない
template <typename T>
struct MonoidGCD {
    using Type = T;
    static T op(T a, T b) { return std::gcd(a, b); }
    static T e() { return 0; }
};

// これより下わからない
// Rolling Hash (文字列一致判定など)
struct HashNode { ll hash, p_pow; };
template <ll MOD = 1000000007, ll BASE = 10007> struct MonoidRollingHash {
    using Type = HashNode;
    static Type op(Type l, Type r) {
        return { (l.hash * r.p_pow + r.hash) % MOD, (l.p_pow * r.p_pow) % MOD };
    }
    static Type e() { return {0, 1}; }
};

// 最大連続部分和 (GSS)
struct GSSNode { ll sum, l_max, r_max, res; };
struct MonoidGSS {
    using Type = GSSNode;
    static Type op(Type l, Type r) {
        return {
            l.sum + r.sum,
            max(l.l_max, l.sum + r.l_max),
            max(r.r_max, r.sum + l.r_max),
            max({l.res, r.res, l.r_max + r.l_max})
        };
    }
    static Type e() { return {0, -INF, -INF, -INF}; }
};

// 2x2 行列積
template <typename T, ll MOD = 998244353> struct MonoidMatrix22 {
    struct Matrix { T a, b, c, d; };
    using Type = Matrix;
    static Type op(Type l, Type r) {
        return {
            (l.a * r.a + l.b * r.c) % MOD,
            (l.a * r.b + l.b * r.d) % MOD,
            (l.c * r.a + l.d * r.c) % MOD,
            (l.c * r.b + l.d * r.d) % MOD
        };
    }
    static Type e() { return {1, 0, 0, 1}; }
};