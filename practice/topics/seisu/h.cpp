#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define each(x, a) for (auto& x : a)
#define each2(a, b, c) for (auto& [a, b] : c)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) ((int)(x).size())
const string alpha = "abcdefghijklmnopqrstuvwxyz";
const string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr ll INF = (1LL << 60);
constexpr int INT_INF = (1 << 30);
const ll M = 1000000007;

int main() {
    ll n;
    cin >> n;
    map<int, int> mp;
    for (int i = 2; i <= n; i++) {
        int k = i;
        for (int j = 2; j * j <= i; j++) {
            int cnt = 0;
            if (k % j != 0) continue;
            while (k % j == 0) {
                k /= j;
                cnt++;
            }
            mp[j] += cnt;
        }
        if (k != 1) mp[k]++;
    }

    ll sum = 1;
    each2(a, b, mp) {
        // cout << a << " " << b << endl;
        sum = sum * (b + 1) % M;
    }
    cout << sum << endl;

    return 0;
}