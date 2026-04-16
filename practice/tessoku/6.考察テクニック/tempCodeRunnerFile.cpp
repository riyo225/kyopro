#include <bits/stdc++.h>
using namespace std;

int n, q;
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
            a[x-1] = y;
        }
        if (num == 2) reverse(a.begin(), a.end());
        if (num == 3) cout << a[x-1] << endl;
    }
}