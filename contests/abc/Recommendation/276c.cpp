#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n;
int p[109];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for (int i = n; i > 1; i--) {
        if (p[i] < p[i-1]) {
            int x = p[i-1];
            sort(p+i, p+n+1, greater<int>());
            cout << endl;
            int pos = lower_bound(p+i, p+n+1, x, greater<int>()) - p;            
            swap(p[i-1], p[pos]);
            break;
        }
    }
    
    rep(i, n) {
        cout << p[i+1] << " ";
    }
    cout << endl;
    return 0;
}