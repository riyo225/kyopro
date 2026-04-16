#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int main() {
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n);
    map<ll, ll> mp;
    rep(i, n) {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(all(a));
    ll cnt = 0;
    vector<bool> f(mp.size());
    for (auto [k, v] : mp) {
        if (k < a[0] + d) {
            continue;
        }
        if (v <= 0) continue;
        if (mp.count(k+d) && mp[k+d] > 0) {
            if (mp.count(k-d) && mp[k-d] > 0) {
                if (v >= mp[k+d] + mp[k-d]) {
                    cnt += (mp[k+d] + mp[k-d]);
                    mp[k+d] = 0;
                    mp[k-d] = 0;
                }
                else {
                    cnt += v;
                    mp[k] = 0;
                }
            }
            else {
                if (mp.count(k+2*d) && mp[k+2*d] > 0) continue;
                else {
                    if (mp[k+d] > v) {
                        cnt += v;
                        mp[k] = 0;
                    }
                    else {
                        cnt += mp[k+d];
                        mp[k+d] = 0;
                    }
                }
            }
        }
        else if (mp.count(k-d) && mp[k-d] > 0) {
            if (mp[k-d] > v) {
                cnt += v;
                mp[k-d] = 0;
            }
            else {
                cnt += mp[k-d];
                mp[k] = 0;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}