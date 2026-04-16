#include <bits/stdc++.h>
using namespace std;

int n, q;
int a[100009], b[100009], k[100009];

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> b[i] >> k[i];
    }

    sort(a+1, a+n+1);

    int pos;
    for (int i = 1; i <= q; i++) {
        priority_queue<int> pq;

        pos = lower_bound(a+1, a+n+1, b[i])-a;

        for (int j = max(1, pos-k[i]); j <= min(n, pos+k[i]); j++) {
            pq.push(abs(a[j] - b[i]));
            if (pq.size() > k[i]) {
                pq.pop();
            }
        }
        cout << pq.top() << endl;
    }
}