#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[309], b[309];

int getScore(int x, int y) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (x <= a[i] && a[i] <= x+k && y <= b[i] && b[i] <= y+k) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];

    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            int score = getScore(i, j);
            ans = max(ans, score);
        }
    }

    cout << ans << endl;
    return 0;
}