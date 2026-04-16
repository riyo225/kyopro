#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Yes(b) ((b)?"Yes":"No")
#define YES(b) ((b)?"YES":"NO")
using vi = vector<int>;

int main() {
   int n, m;
   cin >> n >> m;
   vi a(n), b(m), c(n+m);
   rep(i, n) cin >> a[i];
   rep(i, m) cin >> b[i];

   rep(i, n) c[i] = a[i];
   rep(i, m) c[i + n] = b[i];

   sort(all(c));
   sort(all(a));
   sort(all(b));
   bool flag = false;

   for (int i = 0; i < n-1; i++) {
    for (int j = 0; j < m-1; j++) {
        if (b[j] <= a[i]) {
            cout << b[j] << " " << a[i] << endl;
            if (a[i+1] <= b[i+1]) flag = true;
            cout << a[i+1] << " " << b[j+1] << endl;
            break;
        }
    }
   }
   if (flag) {
    cout << "Yes" << endl;
   }
   else {
    cout << "No" << endl;
   }
}