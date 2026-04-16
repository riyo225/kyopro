#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
// sortmacro
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define GT greater<int>()
// priority_queue
#define VG vector<int>, greater<int>

// variables
ll r;
vector<ll> vec;
bool flag = false;
ll ans = 0;

int main() {
    cin >> r;

    ll x = 0;
    ll y = r;
    rrep(i, r) {
        if (pow(x+0.5, 2)+pow(y-0.5, 2) <= r*r) {
            vec.push_back(y-1);
        }
        else {
            flag = false;
            while (flag == false) {
                y--;
                if (pow(x+0.5, 2)+pow(y-0.5, 2) < r*r) {
                    vec.push_back(y-1);
                    flag = true;
                }
            }
        }
        x++;
    }

    rep(i, vec.size()) {
        ans += vec[i];
    }

    cout << ans * 4 + 1 << endl;

    return 0;
}