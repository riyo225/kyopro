#include <bits/stdc++.h>
using namespace std;

int q;
int QueryType[100009], Score[100009];
string name[100009];
map<string, int> Map;

int main() {
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> QueryType[i];
        if (QueryType[i] == 1) cin >> name[i] >> Score[i];
        if (QueryType[i] == 2) cin >> name[i];
    }

    for (int i = 1; i <= q; i++) {
        if (QueryType[i] == 1) Map[name[i]] = Score[i];
        if (QueryType[i] == 2) cout << Map[name[i]] << endl;
    }
    return 0;
}