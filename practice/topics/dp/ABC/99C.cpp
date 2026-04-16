#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;

long long dp[100010];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) dp[i] = INF;

    dp[0] = 0;
}