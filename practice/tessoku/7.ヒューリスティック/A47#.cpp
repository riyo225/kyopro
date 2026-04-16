#include <bits/stdc++.h>
using namespace std;

int n;
int x[159], y[159];
int p[159];

int randInt(int a, int b) {
    return a + rand() % (b - a + 1);
}

double getDistance(int a, int b) {
    return sqrt(pow(x[a] - x[b], 2) + pow(y[a] - y[b], 2));
}

double getScore() {
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += getDistance(p[i], p[i+1]);
    return sum;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];

    p[1] = 1, p[n+1] = 1;
    for (int i = 2; i <= n; i++) p[i] = i;
    
    int currentScore = getScore();
    for (int i = 1; i <= 200000; i++) {
        int l = randInt(2, n);
        int r = randInt(2, n);
        if (l > r) swap(l, r);

        reverse(p + l, p + r + 1);
        double newScore = getScore();

        if (newScore > currentScore) currentScore = newScore;
        else reverse(p + l, p + r + 1);
    }

    for (int i = 1; i <= n + 1; i++) cout << p[i] << endl;
    return 0;    
}