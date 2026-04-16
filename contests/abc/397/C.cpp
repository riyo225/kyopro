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
int a[300009];
int csa[300009];
int csb[300009];
int ans = 0;


int main() {
    cin >> n;
    rrep(i, n) cin >> a[i];

    set<int> s;
    rrep(i, n) {
        s.insert(a[i]);
        csa[i] = s.size();
    }

    set<int> st;
    for (int i = n; i >= 1; i--) {
        st.insert(a[i]);
        csb[i] = st.size();
    }

    for (int i = 1; i <= n-1; i++) {
        ans = max(ans, csa[i] + csb[i+1]);
    }

    cout << ans << endl;
    
    return 0;
}