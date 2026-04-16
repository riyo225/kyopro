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
constexpr ll INF = (1LL << 60);
constexpr int INT_INF = (1 << 30);

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n-1);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n-1) cin >> c[i];
    int sum = 0;
    rep(i, n-1) {
        sum += b[a[i]-1];
        if (a[i] + 1 == a[i+1]) {
            sum += c[a[i]-1];
        }
    }
    sum += b[a[n-1]-1];
    cout << sum << endl;
    return 0;
}