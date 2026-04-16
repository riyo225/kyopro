#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);
using Graph = vector<vector<ll>>;

int main() {
    int n;
    cin >> n;

    Graph graph(n);
    vector<map<int, ll>> dist(n);

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);

        dist[a][b] = 1;
    }

    vector<int> ind(n);
    vector<bool> al(n, false);

    for (int i = 0; i < n; i++) {
        ind[i] = graph[i].size();
    }

    for (int i = 0; i < n; i++) {
        vector<ll> seen(n, -1);
        queue<int> que;

        seen[i] = 0;
        que.push(i);

        while (!que.empty()) {
            int v = que.front();
            que.pop();

            for (int nv : graph[v]) {
                if (seen[nv] != -1) continue;

                seen[nv] = 0;
                dist[i][]++;
                if (ind[nv] == 4 || ind[nv] == 1) {
                    if (i == 5) {
                        cout << i+1 << " " << v+1 << " " << nv+1 << endl;
                    }
                    que.push(nv);
                    if (ind[nv] == 4) {
                        al[i] = true;
                    }
                }
            }
        }
    }

    ll a = -1;
    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
        if (al[i]) {
            a = max(a, dist[i]);
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        if (al[i]) {
            cout << 't' << "  ";
        }
        else {
            cout << 'f' << "  ";
        }
    }
    cout << endl;
    cout << a << endl;
    
    return 0;
}