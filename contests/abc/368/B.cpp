#include <bits/stdc++.h>
using namespace std;

int n;
int a[109];
int counter = 0;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);
    while (a[n-1] != 0) {
        a[n]--;
        a[n-1]--;
        counter++;
        sort(a + 1, a + n + 1);
    }
    cout << counter << endl;
    return 0;
}