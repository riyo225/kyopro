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
const double PI = 3.141592653589793;
struct Edge
{
    ll to;
    ll cost;
};
using Graph = vector<vector<ll>>;


int main() {
    ll n;
    string s;
    cin >> n >> s;
    if (s == "b") {
        cout << 0 << nl;
        return 0;
    } 

    string t = "b";
    bool ans = false;
    for (int i = 1; i < n; i++) {
        if (s == t) {
            ans = true;
            cout << i-1 << nl;
            return 0;
        }
        if (i % 3 == 1) t = 'a' + t + 'c';
        else if (i % 3 == 2) t = 'c' + t + 'a';
        else t = 'b' + t + 'b';
    }
    cout << -1 << nl;

    return 0;
}