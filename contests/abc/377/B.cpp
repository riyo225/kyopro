#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string s[10];
bool c[10][10];

int main() {
    for (int i = 1; i <= 8; i++) cin >> s[i];

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            c[i][j] = true;
        }
    }
    for (int i = 1; i <= 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (s[i][j] == '#') {
                for (int a = 1; a <= 8; a++) {
                    c[i][a] = false;
                    c[a][j+1] = false;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (c[i][j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}