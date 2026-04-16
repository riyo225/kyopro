#include <bits/stdc++.h>
using namespace std;

int n;
int currentCity = 1;
int x[159], y[159];
bool city[159];

double dis(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];

    for (int i = 1; i <= n; i++) city[i] = false;

    int stepCount = n;
    while (stepCount > 0) {
        cout << currentCity << endl;
        int Distance = 1000009, nextCity;
        for (int j = 2; j <= n; j++) {
            if (!city[j]) {
                if (Distance > dis(x[currentCity], y[currentCity], x[j], y[j])) {
                    nextCity = j;
                    Distance = dis(x[currentCity], y[currentCity], x[j], y[j]);
                }
            }
        }
        city[nextCity] = true;
        currentCity = nextCity;
        stepCount--;
    }
    cout << 1 << endl;
    return 0;
}