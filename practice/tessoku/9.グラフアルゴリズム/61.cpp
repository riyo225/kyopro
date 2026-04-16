#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100009], b[100009];
vector<int> g[100009];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i] >> b[i];

    for (int i = 1; i <= m; i++) {
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    for (int i = 1; i <= n; i++) {
        cout << i << ":" << " " << '{';
        for (int j = 0; j < g[i].size(); j++) {
            cout << g[i][j];
            if (j != g[i].size()-1) cout << ", ";
        }
        cout << "}";
        cout << endl;
    }
    return 0;
}