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
    int s;
    cin >> s;

    int cnt = 0;
    if (s >= 100) {
        cnt++;
        s -= 100;
    }
    if (s >= 10) {
        cnt++;
        s -= 10;
    }
    if (s >= 1) cnt++;
    cout << cnt << endl;
    return 0;
}