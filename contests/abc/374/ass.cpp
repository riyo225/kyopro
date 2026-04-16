#include <bits/stdc++.h>
using namespace std;

int is_prime(int n) {
    for (int i = 2; i <= n; i++) {
        int j = 0;
        while (j < i) {
            if (i % j == 0) {
                return true;
                break;
            }
            else {
                continue;
            }
            j++;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        cout << is_prime(i) << endl;
    }
    return 0;
}
