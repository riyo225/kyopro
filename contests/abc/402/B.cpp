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
    int q;
    cin >> q;
    queue<int> que;

    rep(i, q) {
        int one = 0;
        cin >> one;
        if (one == 1) {
            int x;
            cin >> x;
            que.push(x);
        }
        if (one == 2) {
            cout << que.front() << endl;
            que.pop();
        }
    }
    
    return 0;
}