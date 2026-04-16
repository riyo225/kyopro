#include <bits/stdc++.h>
using namespace std;

int n;
int l[300009], r[300009];
vector<pair<int, int>> tmp;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        tmp.push_back(make_pair(r[i], l[i]));
    }

    sort(tmp.begin(), tmp.end());
    for (int i = 1; i <= n; i++) {
        r[i] = tmp[i-1].first;
        l[i] = tmp[i-1].second;
    }

    int currentTime = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (currentTime <= l[i]) {
            currentTime = r[i];
            ans++;
        }
    }
    
    cout << ans << endl;
    return 0;
}