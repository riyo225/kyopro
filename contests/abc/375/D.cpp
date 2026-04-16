#include <bits/stdc++.h>
using namespace std;

string s;
long long cs[30][200009];
long long ans = 0;

int main() {
    cin >> s;
    int n = s.size();

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < n; j++) {
            cs[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        char c = s[i];
        int ii = c - 'A';

        if (i == 0) {
            cs[ii][i]++;
        }
        else {
            cs[ii][i] = cs[ii][i-1] + 1;
        }

        for (int j = 0; j < 26; j++) {
            if (j != ii) {
                cs[j][i] = cs[j][i-1];
            }
        }
    }

    for (int j = 1; j < n-1; j++) {
        for (int i = 0; i < 26; i++) {
            long long s = cs[i][j-1] * (cs[i][n-1] - cs[i][j]);
            ans += s;   
        }
    }
    cout << ans << endl;
    return 0;
}