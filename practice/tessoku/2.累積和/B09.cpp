#include <bits/stdc++.h>
using namespace std;

int n;
int a, b, c, d;
int cs[1509][1509];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        cs[a][b]++;
        cs[a][d]--;
        cs[c][b]--;
        cs[c][d]++;
    }

    for (int i = 0; i < 1509; i++) {
        for (int j = 0; j < 1509; j++) {
            cs[i+1][j] += cs[i][j];
        }
    }

    for (int i = 0; i < 1509; i++) {
        for (int j = 0; j < 1509; j++) {
            cs[j][i+1] += cs[j][i];
        }
    }

    int counter = 0;
    for (int i = 0; i < 1509; i++) {
        for (int j = 0; j < 1509; j++) {
            if (cs[i][j] > 0) counter++;
        }
    }

    cout << counter << endl;
}