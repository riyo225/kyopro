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
int q;
vector<ll> head;
ll last = 0;
ll sub = 0;
ll isub = 0;
queue<ll> len;

int main() {
    cin >> q;

    ll one, two;
    rrep(i, q) {
        cin >> one;
        if (one == 1) {
            cin >> two;
            len.push(two);
            head.push_back(last);
            last += two;
        }
        else if (one == 2) {
            sub += len.front();
            isub += 1;
            len.pop();
        }
        else {
            cin >> two;
            cout << head[two+isub-1] - sub << endl;
        }
    }


    return 0;
}