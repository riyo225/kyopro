#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

const ll M = 1000000000;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> A(n+1);

    int m = k;
    if (n < k) m = n+1;
    for (int i = 0; i < m; i++) {
        A[i] = 1;
    }
    if (k <= n) A[k] = k;
    for (int i = k+1; i <= n; i++) {
        A[i] = 2*A[i-1] - A[i-k-1];
        A[i] %= M;
        while (A[i] < 0) A[i]+=M;
    }

    cout << A[n] << endl;

    return 0;
}