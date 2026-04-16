#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Yes(b) ((b)?"Yes":"No")
#define YES(b) ((b)?"YES":"NO")
using vi = vector<int>;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    vi len(n);
    rep(i, n) cin >> s[i];
    int m = 0;
    rep(i, n) len[i] = s[i].size();
    rep(i, n) m = max(len[i], m);
    vector<string> t(m, "");
    rep(i, n) {
        if (len[i] < m) {         
            s[i] += string(m - len[i], '*');
        }
    }

    // 文字列の行を t に格納
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            t[j] += s[i][j];
        }
    }

    rep(i, m) {
        if (t[i][n-1] == '*') {
            int count = 1;
            for (int j = n-1; j > 0; j--) {
                if (t[i][j] == '*') {
                    count++;
                } else {
                    break;
                }
            }
            t[i] = t[i].substr(0, n - count+1);
        }
    }
    rep(i, m) {
        cout << t[i] << endl;
    }
}