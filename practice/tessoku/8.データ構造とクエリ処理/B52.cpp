#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, x;
string a;
queue<int> t;

int main() {
    cin >> n >> x >> a;
    t.push(x-1);
    
    int y;
    while (!t.empty()) {
        y = t.front();
        a[y] = '@';
        t.pop();
        if (y != 0 && a[y-1] == '.') {
            a[y-1] = '@';
            t.push(y-1);
        }
        if (y != n-1 && a[y+1] == '.') {
            a[y+1] = '@';
            t.push(y+1);
        }
    }

    cout << a << endl;
    return 0;
}