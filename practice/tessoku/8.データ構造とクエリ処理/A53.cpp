#include <bits/stdc++.h>
using namespace std;

int q;
int QueryType[100009], Price[100009];
priority_queue<int, vector<int>, greater<int>> T;

int main() {
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> QueryType[i];
        if (QueryType[i] == 1) cin >> Price[i];
    }

    for (int i = 1; i <= q; i++) {
        if (QueryType[i] == 1) T.push(Price[i]);
        if (QueryType[i] == 2) cout << T.top() << endl;
        if (QueryType[i] == 3) T.pop();
    }
    return 0;
}