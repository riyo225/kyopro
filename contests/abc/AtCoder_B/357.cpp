#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Yes(b) ((b)?"Yes":"No")
#define YES(b) ((b)?"YES":"NO")
using vi = vector<int>;

int main() {
   string s;
   cin >> s;
   string s_up = "";
   string s_lo = "";

   int upsum = 0;
   int losum = 0;
   rep(i, s.size()) {
      if (isupper(s[i])) upsum++;
      else losum++;
   }

   if (upsum > losum) {
      rep(i, s.size()) {
         s_up += toupper(s[i]);
      }
      cout << s_up << endl;
   }
   else {
      rep(i, s.size()) {
         s_lo += tolower(s[i]);
      }
      cout << s_lo << endl;
   }
}