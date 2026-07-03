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

// 素数判定
bool is_prime(ll n) {
    if (n <= 1) return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// 素因数分解
map<ll, ll> prime_factorize(ll n) {
    // {素因数, 指数}
    map<ll, ll> res;
    for (ll i = 2; i * i <= n; i++) {
        while(n % i == 0) { res[i]++; n /= i; }
    }
    if (n > 1) res[n]++;
    return res;
}

// 約数列挙
vector<ll> get_divisors(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i * i != n) res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

#include <bits/stdc++.h>
using namespace std;

// 素因数分解
vector<long long> lpf_array;

// 最小素因数計算
// O(N log log N)
void sieve_for_lpf(long long N) {
    lpf_array.assign(N + 1, 0);

    if (N >= 0) lpf_array[0] = 0;
    if (N >= 1) lpf_array[1] = 1;

    for (long long i = 2; i <= N; i++) {
        lpf_array[i] = i;
    }

    for (long long i = 2; i <= N; i++) {
        if (lpf_array[i] != i) continue;
        
        for (long long j = i * i; j <= N; j += i) {
            if (lpf_array[j] == j) {
                lpf_array[j] = i;
            }
        }
    }
}


int main() {
    setup_fast_io();

    while (true) {
        ll b; cin >> b;
        if (b == 0) break;
        b *= 2;

        auto res = get_divisors(b);

        ll n = sz(res);
        ll max_ = -INF;
        pll ans;
        rep(i, (n+1)/2) {
            ll x = res[i];
            ll y = res[n-1-i];
            if ((y - x + 1) % 2 == 0 && chmax(max_, x)) {
                ans = {(y - x + 1) / 2, x};
            }
        }
        cout << ans.first << " " << ans.second << nl;
    }

    return 0;
}