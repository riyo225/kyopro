#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
// sortmacro
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define GT greater<int>()
// priority_queue
#define VG vector<int>, greater<int>

// variables
int a, b, c;
bool ans = false;

int main() {
    cin >> a >> b >> c;
    
    if (a == b && b == c) {
        ans = true;
    }
    if (a+b == c || a+c == b || b+c == a) {
        ans = true;
    }
    yes_no(ans)

    


    return 0;
}