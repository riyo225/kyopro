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
    int n;
    cin >> n;
    vector<ll> l(87);
    l[0] = 2;
    l[1] = 1;
    for (int i = 2; i <= 86; i++) {
        l[i] = l[i-1] + l[i-2];
    }
    cout << l[n] << endl;
    return 0;
}