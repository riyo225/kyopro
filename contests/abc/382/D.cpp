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
int n, m;
vector<int> g[100009];

void dfs(int x) {

}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n-1; i++) {
        for (int j = 1+10(i-1); j <= m-10(n-i); j++) {
            for (int k = j+10; k <= m-10(n-i-1); k++) {
                g[j].push_back(k);
            }
        }
    }

    

    return 0;
}