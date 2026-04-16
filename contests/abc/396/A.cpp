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
int a[109];
bool ans = false;
int main() {
    cin >> n;
    rrep(i, n) cin >> a[i];

    rrep(i, n-2) {
        if (a[i] == a[i+1] && a[i] == a[i+2]) {
            ans = true;
        } 
    }

    yes_no(ans);

    return 0;
}