#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int main() {
    string s;
    cin >> s;
    int n = s.size();

    int cnt = 0;
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n-k*2; i++) {
            if (i+2*k > n-1) break;
            if (s[i] == 'A' && s[i+k] == 'B' && s[i+2*k] == 'C') {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    
    return 0;
}