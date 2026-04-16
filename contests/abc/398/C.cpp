#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int n; 
int a[300009];
map<int, int> m;

int main() {
    cin >> n;
    rrep(i, n) {
        cin >> a[i];
        m[a[i]]++;
    }

    int num = 0;
    int ans = -1;

    for (const auto& pair : m) {
        if (pair.second == 1) {
            num = max(num, pair.first);
        }
    }

    rrep(i, n) {
        if (a[i] == num) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
    
    return 0;
}