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
constexpr int INT_INF = (1 << 30);

int main() {
    int s;
    cin >> s;
    map<int, int> mp;
    bool flag = false;
    int a = s;
    int cnt = 1;
    while (!flag) {
        cnt++;
        if (a % 2 == 0) {
            a /= 2;
        }
        else {
            a = 3 * a + 1;
        }
        mp[a]++;
        if (mp[a] > 1) {
            cout << cnt << endl;
            flag = true;
        }
    }
    return 0;
}