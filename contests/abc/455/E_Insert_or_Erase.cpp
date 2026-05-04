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

struct DoublyLinkedList {
    const ll HEAD_BASE = -1000000000LL;
    const ll TAIL_BASE = -2000000000LL;
    unordered_map<ll, ll> prv, nxt;

    ll head_id(ll i) { return HEAD_BASE - i; }
    ll tail_id(ll i) { return TAIL_BASE - i; }

    void link(ll a, ll b) {
        nxt[a] = b;
        prv[b] = a;
    }

    // n 個のからの列を作成
    DoublyLinkedList(ll n) {
        for (ll i = 0; i < n; i++) {
            link(head_id(i), tail_id(i));
        }
    }

    // 列 i の末尾に要素 x を追加
    void push_back(ll i, ll x) {
        ll t = tail_id(i);
        ll last_elem = prv[t];
        link(last_elem, x);
        link(x, t);
    }

    // 要素 x の後に y を挿入
    void insert_after(ll x, ll y) {
        ll z = nxt[x];
        link(x, y);
        link(y, z);
    }

    vector<ll> get_list(ll i) {
        vector<ll> res;
        ll cur = nxt[head_id(i)];
        while (cur != tail_id(i)) {
            res.push_back(cur);
            cur = nxt[cur];
        }
        return res;
    }
};


int main() {
    setup_fast_io();

    ll n; cin >> n;
    vll a(n); cin >> a;
    ll q; cin >> q;
    unordered_map<ll, ll> prev, next;

    if (n == 1) {
        prev[a[0]] = -1;
        next[a[0]] = -1;
    } else {
        prev[a[0]] = -1;
        next[a[0]] = a[1];
        prev[a[n-1]] = a[n-2];
        next[a[n-1]] = -1;
        for (int i = 1; i < n-1; i++) {
            prev[a[i]] = a[i-1];
            next[a[i]] = a[i+1]; 
        }
    }
    ll current_head = a[0];

    while (q--) {
        ll type; cin >> type;
        if (type == 1) {
            ll x, y; cin >> x >> y;

            next[y] = next[x];
            if (next[x] != -1) prev[next[x]] = y;
            prev[y] = x;
            next[x] = y;
        }
        else {
            ll x; cin >> x;
            if (prev[x] != -1) next[prev[x]] = next[x];
            if (next[x] != -1) prev[next[x]] = prev[x];

            if (x == current_head) {
                current_head = next[x];
            }

            prev[x] = -2;
            next[x] = -2;
        }
    }

    ll v = current_head;
    while (v != -1) {
        cout << v << (next[v] == -1 ? "" : " ");
        v = next[v];
    }
    cout << nl;
    return 0;
}