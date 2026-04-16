#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N; // 配列サイズ
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i]; // a の入力

    // 累積和
    vector<int> s(N+1, 0); // s[0] = 0 になる
    for (int i = 0; i < N; ++i) s[i+1] = s[i] + a[i];

}