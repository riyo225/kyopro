#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> w(n);
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> x[i];
    }
    vector<int> count(24);
    for (int i = 0; i < 24; i++) {
        vector<int> now(n);
        for (int j = 0; j < n; j++) {
            now[j] = x[j] + i;
            now[j] %= 24;
            if (now[j] >= 9 && now[j] <= 17) {
                count[i] += w[j];
            }
        }
    }
    sort(count.begin(), count.end());
    cout << count[23] << endl;
}