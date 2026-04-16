#include <bits/stdc++.h>
using namespace std;

int n;
int a[200009], b[200009];
int ans = -1;
int sum = 0;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n-1; i++) cin >> b[i];

    sort(a+1, a+n+1);
    sort(b+1, b+n);

    set<int> available;
    for (int i = 1; i <= n-1; i++) {
        available.insert(i);
    }

    for (int i = n; i >= 1; i--) {
        auto pos = lower_bound(b+1, b+n, a[i]) - b;

        auto it = available.lower_bound(pos);

        if (it == available.end()) {
            sum++;
            if (sum == 2) {
                ans = -1;
                break;
            }
            ans = a[i];
        }
        else {
            available.erase(it);
        }
    }
    cout << ans << endl;
}
