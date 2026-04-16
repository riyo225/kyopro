#include <bits/stdc++.h>
using namespace std;

int n, q;
int qt, x, y;
vector<int> g[200009];

int main() {
    cin >> n >> q;

    for (int i = 1; i <= n; i++) g[i].push_back(i);

    for (int i = 1; i <= q; i++) {
        cin >> qt >> x >> y;    

        if (qt == 1) {
            g[x].push_back(y);
            g[y].push_back(x);
        }
        if (qt == 2) {
            sort(g[x].begin(), g[x].end(), greater<int>());
            if (g[x].size() < y) cout << -1 << endl;
            else cout << g[x][y-1] << endl;
        }
    }
    return 0;
}