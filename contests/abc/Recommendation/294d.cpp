#include <bits/stdc++.h>
using namespace std;

// macro
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define GT greater<int>()

// variables
int n, q, s, t;
queue<int> p;
set<int> se;

int main() {
    cin >> n >> q;

    rrep(i, n) {
        p.push(i);
    }

    rrep(i, q) {
        cin >> s;
        if (s == 1) {
            if (!p.empty()) {
                se.insert(p.front());
                p.pop();
            }          
        }
        else if (s == 2) {
            cin >> t;
            se.erase(t);
        }
        else {
            if (!se.empty()) {
                cout << *se.begin() << endl;
                se.erase(se.begin());
            }
        }
    }

    return 0;
}