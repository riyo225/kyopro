#include <bits/stdc++.h>
using namespace std;

// --- エラトステネスの篩 ---
// O(N log log N)
vector<long long> Eratosthenes(long long N) {
    vector<bool> is_prime(N + 1, true);

    // 0, 1はあらかじめふるい落とす
    is_prime[0] = is_prime[1] = false;

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
    for (long long i = 0; i <= N; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    return primes; // 素数のリストを返す
}

// --- 区間篩 [L, R] ---
vector<long long> segmented_sieve(long long L, long long R) {
    vector<bool> is_prime(R - L + 1, true);

    if (L <= 1) { // Lが0か1の場合
        if (0 >= L && 0 <= R) is_prime[0 - L] = false;
        if (1 >= L && 1 <= R) is_prime[1 - L] = false;
    }

    // sqrt(R)までの素数を計算
    long long limit = sqrt(R);
    vector<long long> small_primes = Eratosthenes(limit + 1);

    // 事前計算した素数を使って区間 [L, R] に篩をかける
    for (long long p : small_primes) {
        // p の倍数で L 以上の最初の数を求める
        long long start = max(p * p, (L + p - 1) / p * p);

        for (long long i = start; i <= R; i += p) {
            is_prime[i - L] = false;
        }
    }

    // 区間内の素数のリストを作成
    vector<long long> primes;
    for (long long i = 0; i <= R - L; i++) {
        if (is_prime[i]) {
            primes.push_back(L + i);
        }
    }

    return primes; // 区間内の素数のリストを返す
}