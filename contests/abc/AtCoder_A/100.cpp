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
    int a, b;
    cin >> a >> b;
    int c = 16 - a - b;
    if (a >= b && a <= b+c) {
        cout << "Yay!" << endl;
    }
    else if (a <= b && a+c >= b) {
        cout << "Yay!" << endl;
    }
    else cout << ":(" << endl;
    return 0;
}