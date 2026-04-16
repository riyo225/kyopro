#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
const int INF_INT = 2e9;
const ll INF_LL = 2e18;
const int MOD = 998244353;
// const int MOD = 1000000007;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define rrep(i, n) for (ll i = (ll)(n)-1; i >= 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(x) ((ll)(x).size())
#define nl "\n"
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << nl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << nl;
template<class T> bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }

// #define DEBUG
#ifdef DEBUG
    #define debug(x) cerr << #x << ": " << (x) << endl
    #define debug_vec(vec) { cerr << #vec << ": "; for(const auto& elem : vec) cerr << elem << " "; cerr << endl; }
    #define debug_pair(p) cerr << #p << ": (" << (p).first << ", " << (p).second << ")" << endl
    #define debug_2d_vec(vec2d) { cerr << #vec2d << ":" << endl; for(const auto& row : vec2d) { cerr << "  "; for(const auto& elem : row) cerr << elem << " "; cerr << endl; } }
    #define debug_map(m) { cerr << #m << ": "; for(const auto& [key, val] : m) cerr << "(" << key << ":" << val << ") "; cerr << endl; }
#else
    #define debug(x)
    #define debug_vec(vec)
    #define debug_pair(p)
    #define debug_2d_vec(vec2d)
    #define debug_map(m)
#endif

void setup_fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(15);
}

// using Graph = vector<vector<ll>>;
// using Graph = vector<vector<Edge>>;
namespace RLE {
    template <typename T>
    auto encode (const T& s) {
        ll n = s.size();
        vector<pair<typename T::value_type, ll>> res;
        for (ll l = 0; l < n; ) {
            ll r = l + 1;
            while (r < n && s[l] == 'A' && s[l] == s[r]) r++;
            res.emplace_back(s[l], r - l);
            l = r;
        }
        return res;
    }

    template <typename T>
    T decode(const vector<pair<typename T::value_type, ll>>& encoded) {
        T res;
        for (const auto& [val, count] : encoded) {
            for (ll i = 0; i < count; i++) {
                res.push_back(val);
            }
        }
        return res;
    }
}
int main() {
    setup_fast_io();

    string s, t;
    cin >> s >> t;

    auto ress = RLE::encode(s);
    auto rest = RLE::encode(t);
    vector<pair<char, ll>> vecs, vect;
    for (int i = 0; i < sz(ress); i++) {
        if (ress[i].first != 'A') {
            if (i-1 >= 0 && ress[i-1].first != 'A') vecs.push_back({'A', 0});
            else if (i - 1 < 0) vecs.push_back({'A', 0});
        }
        vecs.push_back(ress[i]);
    }
    if (!vecs.empty() && vecs.back().first != 'A') vecs.push_back({'A', 0});

    for (int i = 0; i < sz(rest); i++) {
        if (rest[i].first != 'A') {
            if (i-1 >= 0 && rest[i-1].first != 'A') vect.push_back({'A', 0});
            else if (i-1<0) vect.push_back({'A', 0});
        }
        vect.push_back(rest[i]);
    }
    if (!vecs.empty() && vect.back().first != 'A') vect.push_back({'A', 0});

    // for (auto p : vecs) {
    //     debug_pair(p);
    // }
     
    // for (auto p : vect) {
    //     debug_pair(p);
    // }

    bool ans = true;
    ll cnt = 0;
    ll n = sz(vecs);
    if (sz(vecs) != sz(vect)) {
        ans = false;
    }
    else {
        rep(i, n) {
            if (vecs[i].first != vect[i].first) {
                ans = false;
                break;
            }
            else if (vecs[i].first != 'A' && vecs[i].second != vect[i].second) {
                ans = false;
                break;
            }
            cnt += abs(vecs[i].second - vect[i].second);
        }
    }

    if (ans) {
        cout << cnt << nl;
    }
    else cout << -1 << nl;
     


    return 0;
}