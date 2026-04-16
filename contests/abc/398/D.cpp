#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

set<pair<int, int>> st;
vector<int> ans;

int main() {
    int n, r, c;
    string s;
    cin >> n >> r >> c >> s;

    int x = 0;
    int y = 0;

    st.insert({0, 0});
    for (int i = 0; i < n; i++) {
        if (s[i] == 'N') {
            x++;
            r++;
        }
        if (s[i] == 'S') {
            x--;
            r--;
        }
        if (s[i] == 'E') {
            y--;
            c--;
        }
        if (s[i] == 'W') {
            y++;
            c++;
        }

        st.insert({x, y});

        if (st.find({r, c}) != st.end()) {
            cout << 1;
        }
        else {
            cout << 0;
        }
    }

    
    
    return 0;
}