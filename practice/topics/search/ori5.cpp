#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define rrep(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define repbit(bit, n) for (ll bit = 0; bit < (1LL << (ll)(n)); bit++)
#define each(x, a) for (auto& x : a)
#define each2(a, b, c) for (auto& [a, b] : c)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) ((ll)(x).size())
#define nl "\n"
template<class T> bool chmax(T& a, const T& b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<class T> bool chmin(T& a, const T& b) {
    if (a > b) { a = b; return true; }
    return false;
}
const string alpha = "abcdefghijklmnopqrstuvwxyz";
const string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr ll INF = (1LL << 60);
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, 1, 0, -1};
struct Edge
{
    ll to;
    ll cost;
};
using Graph = vector<vector<ll>>;

ll n, m;
map<string, ll> ans;

void dfs(Graph& graph, ll v, string s) {
    s += (v + '1');

    for (auto nv : graph[v]) {
        if (sz(s) == n) {
            ans[s]++;
            return;
        }
        dfs(graph, nv, s);
    }
    cout << "--" << nl;
}

int main() {
    cin >> n >> m;
    Graph graph(m);

    rep(i, m) {
        for (ll j = i; j < m; j++) {
            graph[i].push_back(j);
        }
    }

    rep(i, m) {
        dfs(graph, i, "");
    }

    each2(a, b, ans) {
        cout << a << " " << b << endl;
    }
    
    return 0;
}