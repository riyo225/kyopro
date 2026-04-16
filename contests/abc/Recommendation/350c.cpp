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

// variables
int n;
int a[200009];
vector<pair<int, int>> p;

void hp(vector<int>& v, int x) {
    for (int i = x; i >= 2; i--) {
        if (v[i] < v[i/2]) {
            p.push_back(make_pair(v[i], v[i/2]));
            swap(v[i], v[i/2]);
        }
    }
    v.erase(v.begin()+1);
    if (v.size() != 1) {
        hp(v, x-1);
    }
}

int main() {
    cin >> n;
    rrep(i, n) {
        cin >> a[i];
    }

    vector<int> tr;
    tr.push_back(0);
    rrep(i, n) {
        tr.push_back(a[i]);
    }

    hp(tr, n);

    cout << p.size() << endl;
    rep(i, p.size()) {
        cout << p[i].first << " " << p[i].second << endl;
    }
    return 0;
}