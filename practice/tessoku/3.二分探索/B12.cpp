#include <iostream>
#include <cmath>
using namespace std;

double n;

bool check(double m) {
    double sum = pow(m, 3) + m;
    if (abs(m - n) < 0.001) cout << m << endl;
    if (sum >= n) return true;
    return false;
}

int main() {
    double l = 1, r = 100000;
    while (l < r) {
        double m = (l + r) / 2.0;
        bool ans = check(m);
        if (ans) r = m;
        else l = m + 0.0005;
    }
    return 0;
}