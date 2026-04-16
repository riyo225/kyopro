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
const string alpha = "abcdefghijklmnopqrstuvwxyz";
const string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr ll INF = (1LL << 60);
constexpr int INT_INF = (1 << 30);

int main() {
    string s;
    cin >> s;
    int n = sz(s)-1;
    ll sum = 0;
    repbit(b, n) {
        vector<ll> vec;
        int index = 0;
        int cnt = 1;
        rep(i, n) {
            if (!(b & (1<<i))) {
                // i番目にプラスをいれない
                cnt++;
            }
            else {
                ll a = stoll(s.substr(index, cnt));
                vec.push_back(a);
                index += cnt;
                cnt = 1;
            }
        }
        ll a = stoll(s.substr(index, cnt));
        vec.push_back(a);
        rep(i, sz(vec)) {
            sum += vec[i];
            // cout << vec[i] << endl;
        }
    }
    cout << sum << endl;
    return 0;
}