#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, m;
int l[200009], r[200009];
vector<pair<int, int>> p;
int s[200009];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        p.push_back(make_pair(l[i], r[i]));
    }

    sort(p.begin(), p.end());

    ll ans = 0;
    
    for (int i = 0; i < m; i++) {
        int mi = INT_MAX;
        int pos = lower_bound(p.begin(), p.end(), make_pair(i + 1, 0)) - p.begin();

        for (int j = pos; j < p.size(); j++) {
            mi = min(mi, p[j].second);
        }

        if (pos >= p.size() || (mi >= m)) {
            s[i] = m+1;
        }
    }

    for (int i = 0; i < m; i++) {
        ans += (s[i] - (i + 1));
    }
    cout << ans << endl;
    return 0;
}
