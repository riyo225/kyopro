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
int n;
int a[100009], b[100009];
ll sum = 0, Sum = 0;
vector<ll> S;
int ans;

int main() {
    cin >> n;
    rrep(i, n) cin >> a[i];
    rrep(i, n) cin >> b[i];

    rrep(i, n) {
        int sub = a[i] - b[i];
        if (sub >= 0) {
            S.push_back(sub);
            Sum += sub;
        }
        else {
            sum += sub;
        }
    }

    if (Sum + sum < 0) {
        ans = -1;
    }
    else {
        
    }

    return 0;
}