// [prefix: quadll, solve]

vector<ll> quadll(ll A, ll B, ll C) {
    vector<ll> res;
    if (A == 0) {
        if (B != 0 && C % B == 0) res.push_back(-C / B);
        return res;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    }

    __int128_t a = A, b = B, c = C;
    __int128_t D = b * b - 4 * a * c;
    if (D < 0) return res;

    ll sq = round(sqrt((ll)D));
    if ((__int128_t)sq * sq == D) {
        if ((-B + sq) % (2 * A) == 0) {
            res.push_back((-B + sq) / (2 * A));
        }
        if (sq > 0 && (-B - sq) % (2 * A) == 0) {
            res.push_back((-B - sq) / (2 * A));
        } 
    }
    sort(all(res));
    return res;
}