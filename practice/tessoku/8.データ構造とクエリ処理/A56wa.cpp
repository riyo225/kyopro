#include <bits/stdc++.h>
using namespace std;

long long n, q;
string s;
long long a[200009], b[200009], c[200009], d[200009];

long long mod = 2147483647;
long long t[200009], h[200009];
long long power100[200009];

long long Hash_Value(int l, int r) {
    long long val = h[r] - (h[l-1] * power100[r-l+1] % mod);
    if (val < 0) val += mod;
    return val;
}

int main() {
    cin >> n >> q >> s;
    for (int i = 1; i <= q; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    
    // 文字を数値に変換
    for (int i = 1; i <= n; i++) t[i] = (s[i-1] - 'a') + 1;

    // 100のn乗を前計算する（B^0, B^1, B^2 ...）
    power100[0] = 1;
    for (int i = 1; i <= n; i++) power100[i] = 100LL * power100[i-1] % mod;

    h[0] = 0;
    for (int i = 1; i <= n; i++) h[i] = (100LL + h[i-1] + t[i]) % mod;

    for (int i = 1; i <= q; i++) {
        long long hash1 = Hash_Value(a[i], b[i]);
        long long hash2 = Hash_Value(c[i], d[i]);
        if (hash1 == hash2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}