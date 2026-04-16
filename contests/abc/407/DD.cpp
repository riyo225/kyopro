#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rall(v) v.rbegin(), v.rend()
const ll dx[2] = {1, 0}; // 右・下だけ見ればよい
const ll dy[2] = {0, 1};
#define nl "\n"

int main() {
    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> a(H, vector<ll>(W));
    rep(i, H) rep(j, W) cin >> a[i][j];

    ll s = 0;
    rep(i, H) rep(j, W) s ^= a[i][j]; // 初期 XOR

    // 隣接ペアの候補を列挙
    vector<tuple<ll, ll, ll, ll>> candidates; // {val, i1, j1, i2, j2}
    rep(i, H) rep(j, W) {
        rep(k, 2) {
            ll ni = i + dx[k], nj = j + dy[k];
            if (ni >= H || nj >= W) continue;
            ll val = a[i][j] ^ a[ni][nj];
            candidates.emplace_back(val, i, j, ni, nj);
        }
    }

    // 降順にソート（XORが大きいペアを優先）
    sort(rall(candidates));

    vector<vector<bool>> used(H, vector<bool>(W, false));
    ll sum = s;

    for (auto &[val, i1, j1, i2, j2] : candidates) {
        if (used[i1][j1] || used[i2][j2]) continue;
        used[i1][j1] = used[i2][j2] = true;
        sum ^= val;
    }

    cout << sum << nl;
    return 0;
}
