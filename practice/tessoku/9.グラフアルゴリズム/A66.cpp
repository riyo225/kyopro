#include <bits/stdc++.h>
using namespace std;

int n, q, u, v;
vector<int> g[100009];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> q >> u >> v;

        if (q == 1) {
            g[u].push_back(v);
            g[v].push_back(u);
        }
        else {
            
        }
    }
    
}