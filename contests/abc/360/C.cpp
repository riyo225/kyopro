#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    set<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(a[i]);
    }
    for (int i = 0; i < n; i++) cin >> w[i];
    vector<int> mini;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector<int> vi(n);
                if (i == a[j]) {
                vi.push_back(w[j]);
            }
            sort(vi.begin(), vi.end());
            if (vi.size() != 1) {
                for (int i = 0; i < vi.size() - 1; i++) {
                    mini.push_back(vi[i]);
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!s.count(i+1)) {
            count++;
        }
    }

    sort(mini.begin(), mini.end());
    int ans = 0;
    for (int i = 0; i < count; i++) {
        ans += mini[i];
    }
    cout << ans << endl;
    for (auto c : mini) {
        cout << c << endl;
    }
}