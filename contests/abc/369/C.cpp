#include <bits/stdc++.h>
using namespace std;

int n;
int a[200009];
vector<int> sub;
int ans[200009];
long long A = 0;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) ans[i] = 2;
    ans[1] = 1;

    for (int i = 1; i < n; i++) {
        sub.push_back(a[i+1] - a[i]);
        if (i != 1) {
            if (sub[i-1] == sub[i-2]) {
                ans[i+1] = ans[i] + 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        A += ans[i];
    }
    
    cout << A << endl;
    return 0;
}