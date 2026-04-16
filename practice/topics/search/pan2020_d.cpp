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

ll n;

void dfs(Graph& graph, ll v, string s, vector<ll>& cnt) {
    s += (v + 'a');
    cnt[v]++;

    for (auto nv : graph[v]) {
        if (sz(s) == n) {
            cout << s << nl;
            return;
        }

        if (sz(s)+1 <= nv) return;
        if (nv != 0 && cnt[nv-1] == 0) return;

        dfs(graph, nv, s, cnt);

        cnt[nv]--;
    }
    cnt[v]--;
}


int main() {
    cin >> n;
    Graph graph(n);
    vector<ll> cnt(n, 0);

    rep(i, n) {
        rep(j, n) {
            graph[i].push_back(j);
        }
    }

    dfs(graph, 0, "", cnt);


    return 0;
}