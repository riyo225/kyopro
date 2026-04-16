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
int n, k;
string s;
int sum = 0;

int main() {
    cin >> n >> k >> s;
    string S = "";
    for (int i = 0; i < k; i++) {
        S += 'O';
    }
    for (int i = 0; i <= n-k; i++) {
        if (s.substr(i, k) == S) {
            for (int j = 0; j < k; j++) {
                s[i+j] = 'X';
            }
            sum += 1;
        }
    }
    cout << sum << endl;
    return 0;
}