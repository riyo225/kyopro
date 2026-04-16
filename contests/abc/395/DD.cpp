#include <bits/stdc++.h>
using namespace std;

#define ll long long

// Union-Find構造体
class UnionFind {
public:
    vector<int> parent;
    UnionFind(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    UnionFind uf(n);

    while (q--) {
        int op;
        cin >> op;
        
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            uf.unite(a, b);
        } 
        else if (op == 2) {
            int a, b;
            cin >> a >> b;
            uf.unite(a, b);
        } 
        else if (op == 3) {
            int a;
            cin >> a;
            cout << uf.find(a) << endl;
        }
    }

    return 0;
}
