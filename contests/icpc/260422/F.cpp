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

    while (true) {
        ll w, h; cin >> w >> h;
        if (w == 0) break;

        vector<vector<ll>> b(h, vector<ll>(w));
        rep(i, h)rep(j, w)
        {
            cin >> b[i][j];
        }

        //  上、左、下、右
        vector<pair<ll, ll>> direction = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        vector<vector<vector<pair<ll, ll>>>> d(h, vector<vector<pair<ll, ll>>>(w, vector<pair<ll,ll>>(4, {-1, -1})));

        pair<ll, ll> start, goal;

        rep(i, h)rep(j, w)
        {
            if (b[i][j] == 1)
            {
                continue;
            }
            else if (b[i][j] == 2)
            {
                start = {i, j};
            }
            else if (b[i][j] == 3)
            {
                goal = {i, j};
            }

            if (b[i][j] != 1)
            {
                rep(k, 4)
                {
                    pair<ll, ll> now = {i, j};
                    while (true)
                    {
                        pair<ll, ll> tmp = {now.first + direction[k].first, now.second + direction[k].second};
                        if (tmp.first < 0 || tmp.first >= h || tmp.second < 0 || tmp.second >= w)
                        {
                            now = {-1, -1};
                            break;
                        }
                        else if (b[tmp.first][tmp.second] == 1)
                        {
                            break;
                        }
                        else
                        {
                            now = tmp;
                        }
                    }
                    d[i][j][k] = now;
                }
            }
        }

        vector<vector<ll>> dist(h, vector<ll>(w, -1));
        queue<pair<ll, ll>> que;

        

        dist[start.first][start.second] = 0;
        que.push(start);

        while (!que.empty())
        {
            pair<ll, ll> v = que.front();
            que.pop();
        
            rep(i, 4)
            {
                pair<ll, ll> nv = d[v.first][v.second][i];
                if (nv.first == -1) continue;
                if (dist[v.first][v.second] + 1 > 10) continue;

                dist[nv.first][nv.second] = dist[v.first][v.second] + 1;
                que.push(nv);
            }
        }

        
        cout << dist[goal.first][goal.second] << endl;
    }

    return 0;
}