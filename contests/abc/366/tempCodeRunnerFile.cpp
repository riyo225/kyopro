#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Yes(b) ((b)?"Yes":"No")
#define YES(b) ((b)?"YES":"NO")
using vi = vector<int>;

int main() {
    int q; cin >> q;
    set<int> s;
    rep(i, q) {
        int a; cin >> a;
        if (a == 1) {
            int x; cin >> x;
            s.insert(x);
        }
        else if (a == 2) {
            int x; cin >> x;
            s.erase(x);
        }
        else {
            cout << s.size() << endl;
        }
    }
}