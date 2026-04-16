#include <bits/stdc++.h>
using namespace std;

int n, m, k, sum = 0;
int a[200009];
vector<pair<int, int>> ans;

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans.push_back(make_pair(i, a[i]));
        sum += a[i];
    }

    int res = k - sum;

    for (int i = 1; i <= n; i++) ans[i] = -1;
    sort()
    
}