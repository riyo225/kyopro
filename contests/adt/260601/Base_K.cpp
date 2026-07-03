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


int main() {
    setup_fast_io();

    // 文字を数字に変換する（A->10）
    auto c2l = [&](char c) -> ll {
        if ('0' <= c && c <= '9') return c - '0';
        if ('a' <= c && c <= 'z') return c - 'a' + 10;
        return c - 'A' + 10;
    };
    
    // 数字を文字に変換する（10->A）
    auto l2c = [&](ll v) -> char {
        if (0 <= v && v <= 9) return (char)(v + '0');
        return (char)(v - 10 + 'A');
    };
    
    // n進法->10進法
    auto base2long = [&](string s, ll base) -> ll {
        ll res = 0;
        for (char c : s) res = res * base + c2l(c);
        return res;
    };
    
    // 10進法->n進法
    auto long2base = [&](ll val, ll base) -> string {
        if (val == 0) return "0";
        string res = "";
        while (val != 0) {
            ll rem = val % base;
            val /= base;
            if (rem < 0) {
                rem += abs(base);
                val += 1;
            }
            res += l2c(rem);
        }
        reverse(all(res));
        return res;
    };

    ll k; cin >> k;
    string a, b; cin >> a >> b;
    ll A = base2long(a, k);
    ll B = base2long(b, k);
    cout << A * B << nl;

    return 0;
}