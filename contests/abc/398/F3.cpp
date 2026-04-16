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
    string t;
    cin >> t;
    int m = t.size();
    string _s = t;
    reverse(_s.begin(), _s.end());

    int n = _s.size();

    // '#'の追加
    string s(2 * n + 1, '#');
    for (int i = 0; i < n; i++) s[2*i+1] = _s[i];
    n = 2*n+1;

    vector<int> rad(n);
    // c: 中心 r: 中心からの距離
    int c = 0, r = 0;

    while (c < n) {
        while (0 <= c-r && c+r < n && s[c-r] == s[c+r]) r++;
        rad[c] = r;

        int k = 1;
        while (0 <= c-k && k+rad[c-k] < r) {
            rad[c+k] = rad[c-k];
            k++;
        } 
        c += k;
        r -= k;
    }

    for (int i = 0; i < n; i++) {
        if (i%2 == 0) {
            rad[i] = (rad[i] - 1) / 2;
        }
        else {
            rad[i] /= 2;
        }
    }

    int pos;
    bool flag;
    for (int i = 1; i < n; i++) {
        if (i%2 == 1 && (i+1)/2 == rad[i]) {
            pos = rad[i];
            flag = true;
        }
        if (i%2 == 0 && i/2 == rad[i]) {
            pos = rad[i];
            flag = false;
        }
    }

    if (flag) {
        cout << t.substr(0, m-pos*2+1) + _s << endl;
    }
    else {
        cout << t.substr(0, m-pos*2) + _s << endl;
    }

    return 0;
}