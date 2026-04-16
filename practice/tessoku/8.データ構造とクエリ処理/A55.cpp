#include <bits/stdc++.h>
using namespace std;

int q;
int QueryType[100009];
int x[100009];
set<int> st;

int main() {
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> QueryType[i] >> x[i];
    }

    for (int i = 1; i <= q; i++) {
        if (QueryType[i] == 1) st.insert(x[i]);
        if (QueryType[i] == 2) st.erase(x[i]);
        if (QueryType[i] == 3) {
            if (st.size() == 0) cout << -1 << endl;
            else {
                auto itr = st.lower_bound(x[i]);
                if (itr == st.end()) cout << -1 << endl;
                else cout << (*itr) << endl;
            }
        }
    }
    return 0;
}