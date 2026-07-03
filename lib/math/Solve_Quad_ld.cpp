// [prefix: quadld, solve]

vector<ld> quadld(ld A, ld B, ld C) {
    vector<ld> res;
    const ld EPS = 1e-9;

    if (abs(A) < EPS) {
        if (abs(B) > EPS) res.push_back(-C / B);
        return res;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    }

    ld D = B * B - 4 * A * C;
    if (D < -EPS) return res;
    if (D < 0) D = 0;

    ld sq = sqrt(D);
    res.push_back((-B - sq) / (2 * A));
    if (D > EPS) res.push_back((-B + sq) / (2 * A));

    sort(all(res));
    return res;
}