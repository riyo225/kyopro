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
int n;
string s[109];
vector<int> vec[19];


int main() {
    cin >> n;
    rrep(i, n) cin >> s[i];

    rrep(i, n) {
        rep(j, 10) {
            int c = stoi(s[i]);
            vec[c].push_back(i);
        }
    }

    rep(i, 10) {
        for (int j = 1; j < s[i].size(); j++) {
            
        } 
    }



    return 0;
}