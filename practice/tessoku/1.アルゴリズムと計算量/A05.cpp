#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int counter = 0;
    for (int i = 1; i <= min(k-2, n); i++) {
        for (int j = 1; j <= min(n, k-1-i); j++) {
            if (k-i-j <= n) counter++;
        }
    }
    cout << counter << endl;
}