#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int main() {
    char a, b;
    cin >> a >> b;
    if (a == 'H') {
        if (b == 'H') cout << 'H' << endl;
        else cout << 'D' << endl;
    }
    else {
        if (b == 'H') cout << 'D' << endl;
        else cout << 'H' << endl;
    }
    return 0;
}