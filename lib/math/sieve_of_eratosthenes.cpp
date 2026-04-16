#include <bits/stdc++.h>
using namespace std;

// エラトステネスの篩
// O(N log log N)
// N : ~ 10^9
vector<long long> Eratosthenes(long long N) {
    vector<bool> is_prime(N+1, true);

    // 0, 1はあらかじめふるい落とす
    if (N >= 0) is_prime[0] = false;
    if (N >= 1) is_prime[1] = false;

    // ふるい
    for (long long i = 2; i * i <= N; i++) {
        // すでに合成数であるものはスキップ
        if (!is_prime[i]) continue;

        // i以外のiの倍数から素数ラベルをふるい落とす
        for (long long j = i * i; j <= N; j += i) {
            is_prime[j] = false;
        }
    }

    // 素数リストの作成
    vector<long long> primes;
    for (long long k = 0; k <= N; k++) {
        if (is_prime[k]) {
            primes.push_back(k);
        }
    }

    return primes; // 素数のリストを返す
}