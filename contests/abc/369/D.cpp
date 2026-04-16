#include <bits/stdc++.h>
using namespace std;

int n;
int a[200009];
queue<int> q;
long long ans;
int A, B, C;


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) q.push(a[i]);

    while (!q.empty()) {
        int a = q.front();
        q.pop();
        int b = q.front();
        q.pop();
        A = a + 2 * b;
        if (!q.empty()) {
            int c = q.front();
            B = a + 2 * c;
            C = b + 2 * c;
            if (A >= B) {
                if (A >= C) ans += A;
                else {
                    ans += C;
                    q.pop();
                }
            }
            else {
                if (B >= C) {
                    ans += B;
                    q.pop();
                }
                else {
                    ans += C;
                    q.pop();
                }
            }
        }
        
    }
    cout << ans << endl;
    return 0;
}