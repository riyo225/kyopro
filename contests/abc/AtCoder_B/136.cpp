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
    if (n < 10) {
        cout << n << endl;
    }
    else if (n < 100) {
        cout << 9 << endl;
    } 
    else if (n < 1000) {
        cout << n - 100 + 1 + 9 << endl;
    }
    else if (n < 10000) {
        cout << 909 << endl;
    }
    else if (n < 100000) {
        cout << 909 + n - 10000 + 1 << endl;
    }
    else {
        cout << 90909 << endl;
    }
    return 0;
}