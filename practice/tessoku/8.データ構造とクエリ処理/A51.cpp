#include <bits/stdc++.h>
using namespace std;

int q;
int QueryType[100009];
string book[100009];
stack<string> s;

int main() {
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> QueryType[i];
        if (QueryType[i] == 1) cin >> book[i];
    }

    for (int i = 1; i <= q; i++) {
        if (QueryType[i] == 1) s.push(book[i]);
        if (QueryType[i] == 2) cout << s.top() << endl;
        if (QueryType[i] == 3) s.pop();
    }
    return 0;
}