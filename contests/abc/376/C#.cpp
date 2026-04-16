#include <bits/stdc++.h>

using namespaces std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n-1);
    for (int &i: a) cin >> i;
    for (int &i: b) cin >> i;
    sort(a.begin(), a.end());
    int ok = 1 << 30, ng = 0;
    auto f = [&]
}