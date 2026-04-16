#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> k;
int sum = 0;

int f(vector<int>& arr) {
    int s = 0;
    for (int i = 0; i < arr.size(); i++) {
        s += arr[i];
    }
    return s;
}

int main() {
    cin >> n;
    k.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        sum += k[i];
    }

    vector<int> l(k.begin(), k.end() + n/2);
    vector<int> r(k.begin() + n/2, k.end());

    for (int i = 0; i < (1 << n); i++) {
        int avg = abs(f(l) - f(r)) / 2;
        int sub = n;
        int a, b;
        for (int j = 0; j < l.size(); j++) {
            for (int k = 0; k < r.size(); k++) {
                if (abs(l[j] - r[k]) < sub) {
                    sub = abs(l[j] - r[k]);
                    a = j;
                    b = k;
                }
            }
        }
        swap(l[a], r[b]);
    }
    int al = 0;
    int ar = 0;
    for (int i = 0; i < l.size(); i++) al += l[i];
    for (int i = 0; i < r.size(); i++) ar += r[i];
    cout << max(al, ar) << endl;
}