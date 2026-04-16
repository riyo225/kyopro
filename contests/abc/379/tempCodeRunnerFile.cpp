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
int f, s;
vector<ll> vec;

int main() {
    cin >> q;
    cin >> f;
    if (f == 1) {
        vec.push_back(0);
    }
    else if (f == 2) {
        cin >> s;
        rep(i, vec.size()) vec[i]+=s;
    }
    else {
        cin >> s;
        int pos = lower_bound(vec.begin(), vec.end(), s) - vec.begin();
        int i = vec.size() - pos;
        cout << i << endl;
        while (i > 0) {
            vec.pop_back();
            i--;
        }
    }

    return 0;
}