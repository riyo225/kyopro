#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    vector<int> d(n); 
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    
    vector<vector<int>> cs(h+1, vector<int> (w+1, 0));
    for (int i = 0; i < n; i++) {
        cs[a[i]-1][b[i]-1]++;
        cs[a[i]-1][d[i]]--;
        cs[c[i]][b[i]-1]--;
        cs[c[i]][d[i]]++;
    }
    
    // 横に累積和
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j < w; j++) {
            cs[i][j+1] += cs[i][j];
        }
    }
    
    // 縦に累積和
    for (int j = 0; j <= w; j++) {
        for (int i = 0; i < h; i++) {
            cs[i+1][j] += cs[i][j];
        }
    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << cs[i][j] << " ";
        }
        cout << endl;
    }
}