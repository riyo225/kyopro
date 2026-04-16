#include <bits/stdc++.h>
using namespace std;

int q;
int QueryType[100009];
string name[100009];
queue<string> T;

int main() {
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> QueryType[i];
        if (QueryType[i] == 1) cin >> name[i];
    }

    for (int i = 1; i <= q; i++) {
        if (QueryType[i] == 1) T.push(name[i]);
        if (QueryType[i] == 2) cout << T.front() << endl;
        if (QueryType[i] == 3) t.pop();
    }
    return 0;
}