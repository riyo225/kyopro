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
    int k, s;
    cin >> k >> s;

    int cnt = 0;
    for (int i = k; i >= 0; i--) {
        if (i+2*k < s) break;
        for (int j = k; j >= 0; j--) {
            if (i+j+k < s) break;
            int l = s - i - j;
            if (l >= 0 && l <= k) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}