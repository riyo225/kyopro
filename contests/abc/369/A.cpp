#include <bits/stdc++.h>
using namespace std;

int main() {
   int a, b;
   cin >> a >> b;

   int ans = 3;
   if (a == b) {
    ans = 1;
   }
   if ((a+b)%2 == 1) {
    ans = 2;
   }
   cout << ans << endl;
   return 0;
}