// [prefix: safe_lcm]

ll safe_lcm(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    a = abs(a); b = abs(b);
    __int128_t res = (__int128_t)a / gcd(a, b) * b;

    if (res > 9223372036854775807LL) return -1;
    return (ll)res;
}