#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100009], b[100009], c[100009];
vector<pair<int, int>> g[100009];

int cur[100009];
bool confirmed[100009];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        g[a[i]].push_back(make_pair(b[i], c[i]));
        g[b[i]].push_back(make_pair(a[i], c[i]));
    }

    for (int i = 1; i <= n; i++) confirmed[i] = false;
    for (int i = 1; i <= n; i++) cur[i] = numeric_limits<int>::max();

    cur[1] = 0;
    pq.push(make_pair(cur[1], 1));
    while (!pq.empty()) {
        int pos = pq.top().second;
        pq.pop();

        if (confirmed[pos] == true) continue;

        confirmed[pos] = true;
        for (int i = 0; i < g[pos].size(); i++) {
            int nex = g[pos][i].first;
            int cost = g[pos][i].second;

            if (cur[nex] > cur[pos] + cost) {
                cur[nex] = cur[pos] + cost;
                pq.push(make_pair(cur[nex], nex));
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (cur[i] == numeric_limits<int>::max()) cout << -1 << endl;
        else cout << cur[i] << endl;
    }
    return 0;
}