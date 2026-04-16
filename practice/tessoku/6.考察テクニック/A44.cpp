#include <bits/stdc++.h>
using namespace std;

int n, q;
bool state = true;
int Query[200009];
vector<int> a;

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) a.push_back(i+1);

    int num, cnt, x, y;
    for (int i = 1; i <= q; i++) {
        cin >> num;
        if (num == 1) {
            cin >> x >> y;
            if (state) a[x-1] = y;
            else a[n-x] = y;
        }
        if (num == 2) state = !state;
        if (num == 3) {
            cin >> x;
            if (state) cout << a[x-1] << endl;
            else cout << a[n-x] << endl;
        }
    }
}