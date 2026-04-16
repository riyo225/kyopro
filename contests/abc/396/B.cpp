#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int q;
stack<int> s;

int main() {
    cin >> q;
    for (int i = 0; i < 100; i++) {
        s.push(0);
    }

    while (q > 0) {
        int one;
        cin >> one;
        if (one == 1) {
            int two;
            cin >> two;
            s.push(two);
        }
        else {
            cout << s.top() << endl;
            s.pop();
        }
        q--;
    }
    
    return 0;
}