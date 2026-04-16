#include <bits/stdc++.h>
using namespace std;

int n;
char a[3009][3009];
int b[3009][3009];

void generatePattern() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int l = min({i, j, n + 1 - i, n + 1 - j});
            b[i][j] = l % 4;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    generatePattern();  
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (b[i][j] == 1)  {
                cout << a[n + 1 - j][i];
            } else if (b[i][j] == 2) {
                cout << a[n + 1 - i][n + 1 - j];
            } else if (b[i][j] == 3) {
                cout << a[j][n + 1 - i];
            } else {
                cout << a[i][j];
            }
        }
        cout << endl;
    }
    
    return 0;
}
