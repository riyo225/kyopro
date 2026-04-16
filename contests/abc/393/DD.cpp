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
    int n; 
    string s;
    cin >> n >> s;

    int k = 0;
    rep(i, n) {
        int j = 0;
        if (s[i] == '1') {
            while (s[i+j] == '1') {
                j++;
            }
            k++;
        }
    }

    if (k == 1) {
        cout << s << endl;
        return 0;
    }

    
    
    return 0;
}