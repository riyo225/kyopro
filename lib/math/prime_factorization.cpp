#include <bits/stdc++.h>
using namespace std;

// 素因数分解
vector<long long> lpf_array;

// 最小素因数計算
// O(N log log N)
void sieve_for_lpf(long long N) {
    lpf_array.assign(N + 1, 0);

    if (N >= 0) lpf_array[0] = 0;
    if (N >= 1) lpf_array[1] = 1;

    for (long long i = 2; i <= N; i++) {
        lpf_array[i] = i;
    }

    for (long long i = 2; i <= N; i++) {
        if (lpf_array[i] != i) continue;
        
        for (long long j = i * i; j <= N; j += i) {
            if (lpf_array[j] == j) {
                lpf_array[j] = i;
            }
        }
    }
}

// 高速素因数分解
// O(log N)
map<long long, long long> prime_factorize_fase(long long N) {
    map<long long, long long> factors;

    if (N <= 1) {
        return factors;
    }

    // lpf 配列が使えない場合のフォールバック
    // O(sqrt N)
    if (N >= lpf_array.size() || lpf_array[N] == 0) {
        while (N % 2 == 0) {
            factors[2]++;
            N /= 2;
        }

        for (long long i = 3; i * i <= N; i += 2) {
            while (N % i == 0) {
                factors[i]++;
                N /= i;
            }
        }

        if (N > 1) {
            factors[N]++;
        }
        return factors;
    }

    // lpf 配列が使える場合
    while (N > 1) {
        long long p = lpf_array[N];
        factors[p]++;
        N /= p;
    }

    return factors;
}