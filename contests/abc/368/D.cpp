#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[200009], b[200009], v[200009];
vector<int> g[200009];
bool visited[200009];
bool V[200009];
set<int> ans;

int DFS(int pos, int x) {
    ans.insert(pos);
    for (int i = 0; i < g[pos].size(); i++) {
        int nex = g[pos][i];
        if (V[nex] != true) {
            V[nex] = true;
            DFS(nex, x);
        }
        else return x;
    }
}

void dfs(int pos) {
    visited[pos] = true;
    if (V[pos] == true) {
        int g = DFS(pos, pos);
        dfs(g);
    } 
    for (int i = 0; i < g[pos].size(); i++) {
        int nex = g[pos][i];
        if (visited[nex] == false) dfs(nex);
    }
    return;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n-1; i++) cin >> a[i] >> b[i];
    for (int i = 1; i <= k; i++) cin >> v[i];

    for (int i = 1; i <= n; i++) visited[i] = false;
    for (int i = 1; i <= k; i++) V[i] = true;

    dfs(v[1]);
    cout << ans.size() << endl;
    return 0;
}