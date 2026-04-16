#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int q;
    cin >> q;
    vector<int> l(q);
    vector<int> r(q);
    for (int i = 0; i < q; i++) cin >> l[i] >> r[i];

    vector<int> cs(n + 1, 0);
    for (int i = 0; i < n; i++) cs[i + 1] = cs[i] + a[i];

    for (int i = 0; i < q; i++) {
        int win = cs[r[i]] - cs[l[i] - 1];
        int total = r[i] - l[i] + 1;
        int lose = total - win;
        if (win > lose) cout << "win" << endl;
        else if (lose > win) cout << "lose" << endl;
        else cout << "draw" << endl;
    }
}
