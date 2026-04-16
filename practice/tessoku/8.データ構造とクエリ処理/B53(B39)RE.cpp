#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, d, sum;
int x[200009], y[200009];
priority_queue<int> pq;

int main() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    
    for (int today = 1; today <= d; today++) {
        for (int i = 1; i <= n; i++) {
            if (today == x[i]) pq.push(y[i]);
        }
        sum += pq.top();
        pq.pop();
    }
    cout << sum << endl;
    return 0;
}