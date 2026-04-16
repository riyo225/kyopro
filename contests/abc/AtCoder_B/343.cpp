#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> data(n, vector<int> (n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> data[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (data[i][j] == 1) {
                cout << j+1;
                if (i != n-1 || j != n-1) cout << " "; 
            }
        }
        cout << endl;
    }
}