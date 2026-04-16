#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    string date;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d[i]; j++) {
            date = to_string(i+1) + to_string(j+1);
            for (int k = 0; k < date.size(); k++) {
                if (date[k] != date[0]) {
                    break;
                }
                if (k == date.size() - 1) {
                    count++;
                }
            }
        }
    }
    cout << count << endl;
}