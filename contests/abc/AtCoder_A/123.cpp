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
    vector<int> a(5);
    rep(i, 5) cin >> a[i];
    int k;
    cin >> k;
    bool ans = true;
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 5; j++) {
            if (abs(a[j] - a[i]) > k) ans = false;
        }
    }
    if (ans) cout << "Yay!" << endl;
    else cout << ":(" << endl;
    return 0;
}