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
string s;
vector<int> vec;

int main() {
    cin >> s;
    int a = 0;
    int b = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '|') {
            b = i;
            vec.push_back(b-a-1);
            a = i;
        }
    }

    rep(i, vec.size()) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}