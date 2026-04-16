#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

ll n;
const ll N = 1000000;
ll cu[1000009];
bool flag = false;

int main() {
    cin >> n;

    for (ll i = 1; i <= N; i++) {
        cu[i] = i * i * i;
    }

    ll x = -1;
    ll y = -1;
    for (ll i = 1; i <= N; i++) {
        auto it_y = lower_bound(cu+1, cu+i, cu[i]-n);

        if (it_y != cu+i && *it_y == cu[i] - n) {
            x = i;
            y = it_y - cu;
            flag = true;
            break;
        }
    }

    if (flag) {
        cout << x << " " << y << endl;
    }
    else {
        cout << -1 << endl;
    }
    
    return 0;
}