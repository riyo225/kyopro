#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int n;

int main() {
    cin >> n;
    if (n%2 == 0) {
        for (int i = 0; i < n/2-1; i++) {
            cout << '-';
        }
        cout << "==";
        for (int i = 0; i < n/2-1; i++) {
            cout << '-';
        }
    }
    else {
        for (int i = 0; i < n/2; i++) {
            cout << '-';
        }
        cout << '=';
        for (int i = 0; i < n/2; i++) {
            cout << '-';
        }
    }
    cout << endl;
    
    return 0;
}