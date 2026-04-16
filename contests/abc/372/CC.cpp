#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, q;
string s;
int x[200009], c[200009];



int main() {
    cin >> n >> q;
    cin >> s;
    for (int i = 1; i <= q; i++) cin >> x[i] >> c[i];

    for (int i = 1; i <= q; i++) {
        s[x[i]-1] = c[i];
        
    }
}