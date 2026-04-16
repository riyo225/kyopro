#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    
    UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) par[i] = i;
    }
    
    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }
    
    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    void print() {
        cout << "=== UnionFind Status ===\n";
        for (int i = 0; i < par.size(); ++i) {
            cout << "node " << i+1 << ": parent = " << par[i]+1 << "\n";
        }
        cout << "=========================\n";
    }
};


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ans(n);
    vector<int> cnt(n);
    queue<int> a;
    queue<int> b;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a.push(u);
        b.push(v);
    }

    UnionFind tree(n);

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < a.size(); i++) {
            if (a.front() <= k && b.front() <= k) {
                tree.unite(a.front(), b.front());
                a.pop();
                b.pop();
            }
        }

        bool flag = true;
        for (int i = 0; i < k; i++) {
            if (!tree.same(0, i)) {
                flag = false;
                ans[k] = -1;
                break;
            }
        }

        if (flag) {
            for (int i = 0; i < a.size(); i++) {
                if (a.front() <= k || b.front() <= k) {
                    cnt[k]++;
                    int c, d;
                    c = a.front();
                    d = b.front();
                    a.pop();
                    b.pop();
                    a.push(c);
                    b.push(d);
                }
            }
        }

        tree.print();

    }

    return 0;
}