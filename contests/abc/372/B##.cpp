#include <bits/stdc++.h>
using namespace std;

int m;
vector<int> p;
vector<int> ans;

void search(int x) {
    while (x > 0) {
        int pos = upper_bound(p.begin(), p.end(), x) - p.begin();
        x -= p[pos-1];
        ans.push_back(pos-1);
    }
}

int main() {
    cin >> m;

    for (int i = 0; i <= 10; i++) p.push_back(pow(3, i));

    search(m);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}