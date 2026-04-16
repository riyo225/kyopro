#include <bits/stdc++.h>
using namespace std;

int n;
double x[200009], y[200009];

double dis(double x, double y) {
    return pow((pow(x, 2) + pow(y, 2)), 0.5);
}

int main() {
    cin >> n;
    double a = 0, b = 0;
    double cos = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 1; i <= n; i++) {
        cos += dis(a - x[i], b - y[i]);
        a = x[i];
        b = y[i];
    }
    cos += dis(a, b);

    
    cout << fixed << setprecision(10) << cos << endl;
    return 0;
}
