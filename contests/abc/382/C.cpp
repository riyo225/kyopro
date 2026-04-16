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
int n, m;
int a[200009], b[200009];
vector<int> vec;
vector<int> it;
int ans[200009];

int main() {
    cin >> n >> m;
    rrep(i, n) cin >> a[i];
    rrep(i, m) cin >> b[i];

    int x = a[1];
    vec.push_back(a[1]);
    it.push_back(1);
    for (int i = 2; i <= n; i++) {
        if (x > a[i]) {
            vec.push_back(a[i]);
            it.push_back(i);
            x = a[i];
        }
    }

    sort(all(vec));
    sort(rall(it));
    int y = vec.size();

    rrep(i, m) {
        int pos = upper_bound(vec.begin(), vec.end(), b[i]) - vec.begin();

        if (it[pos-1] == 0) {
            cout << -1 << endl;
        } 
        else {
            cout << it[pos-1] << endl; 
        }
    }



    return 0;
}