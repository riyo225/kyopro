#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define each(x, a) for (auto& x : a)
#define each2(a, b, c) for (auto& [a, b] : c)
#define repbit(bit, n) for (int bit = 0; bit < (1<<(int)n); bit++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) ((int)(x).size())
#define nl "\n"
const string alpha = "abcdefghijklmnopqrstuvwxyz";
const string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr ll INF = (1LL << 60);
constexpr int INT_INF = (1 << 30);
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

bool ans[100200];

int main() {
    ll x;
    cin >> x;

    ans[100] = true;
    ans[101] = true;
    ans[102] = true;
    ans[103] = true;
    ans[104] = true;
    ans[105] = true;

    for (int i = 100; i <= 100000; i++) {
        if (ans[i]) ans[i+100] = true;
        if (ans[i]) ans[i+101] = true;
        if (ans[i]) ans[i+102] = true;
        if (ans[i]) ans[i+103] = true;
        if (ans[i]) ans[i+104] = true;
        if (ans[i]) ans[i+105] = true;
    }

    if (ans[x]) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}