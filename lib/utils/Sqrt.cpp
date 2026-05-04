// [prefix: sqrt]

ll isqrt(ll n) {
    if (n <= 0) return 0;
    ll ok = 0, ng = 3037000500LL;
    while (ng - ok > 1) {
        ll mid = ok + (ng - ok) / 2;
        if (mid <= n / mid) ok = mid;
        else ng = mid;
    }
    return ok;
}