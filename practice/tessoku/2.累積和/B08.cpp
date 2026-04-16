#include <iostream>
using namespace std;

int n, x[100009], y[100009], q, cs[1509][1509], a[1509][1509];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    cin >> q;
    for (int i = 0; i < n; i++) a[x[i]][y[i]]++;

    for (int i = 0; i < 1510; i++) {
        for (int j = 0; j < 1510; j++) cs[i+1][j+1] = cs[i+1][j] + cs[i][j+1] - cs[i][j] + a[i+1][j+1];
    }

    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << cs[c][d] - cs[a-1][d] - cs[c][b-1] + cs[a-1][b-1] << endl;
    }
}

// #include <iostream>
// #include <algorithm>
// using namespace std;

// int n, x[100009], y[100009], q, cs[1509][1509], z[1509][1509];

// int main() {
//     cin >> n;
//     for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
//     cin >> q;
//     cout << q << endl;
//     for (int i = 0; i < n; i++) z[x[i]][y[i]]++;
//     cout << q << endl;
    
//     sort(x, x + n);
//     int x_max = x[n-1];
//     sort(y, y + n);
//     int y_max = y[n-1];
    
//     int c_max = max(x_max, y_max);

//     for (int i = 0; i < c_max; i++) {
//         for (int j = 0; j < 1510; j++) cs[i+1][j+1] = cs[i+1][j] + cs[i][j+1] - cs[i][j] + z[i+1][j+1];
//         cout << q << endl;
//     }
//     cout << q << endl;

//     for (int i = 0; i < q; i++) {
//         int a, b, c, d;
//         cin >> a >> b >> c >> d;
//         cout << cs[c][d] - cs[a-1][d] - cs[c][b-1] + cs[a-1][b-1] << endl;
//     }
// }