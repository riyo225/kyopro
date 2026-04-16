#include <bits/stdc++.h>
using namespace std;

#define ll long long

class SegmentTree {
    public:
    int dat[300000], siz = 1;

    void init(int N) {
        siz = 1;
        while (siz < N) siz *= 2;
        for (int i = 1; i < siz * 2; i++) dat[i] = 0;
    };

    void update(int pos, int x) {
        pos = pos + siz - 1;
        dat[pos] = x;
        while (pos >= 2) {
            pos /= 2;
            dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]);
        };
    };

    // range of search => l ~ r-1!!!
    int query(int l, int r, int a, int b, int u) {
        if (r <= a || b <= l) return -1000000000;
        if (l <= a && b <= r) return dat[u];
        int m = (a + b) / 2;
        int ansl = query(l, r, a, m, u * 2);
        int ansr = query(l, r, m, b, u * 2 + 1);
        return max(ansl, ansr);
    };
};

int n, q;
int qt, f, t;
SegmentTree Z;

int main() {
    cin >> n >> q;

    Z.init(n);
    for (int i = 1; i <= q; i++) {
        cin >> qt >> f >> t;
        if (qt == 1) {
            Z.update(f, t);
        };
        if (qt == 2) {
            int ans = Z.query(f, t, 1, Z.siz + 1, 1);
            cout << ans << endl;
        };
    }
    return 0;
}