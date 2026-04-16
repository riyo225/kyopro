#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define Yes(b) ((b)?"Yes":"No")
#define YES(b) ((b)?"YES":"NO")
using vi = vector<int>;

signed main() {
    bool flag = false;
    float a, A, b, B, c, C;
    cin >> a >> A >> b >> B >> c >> C;
    float k1, k2, k3;

    k1 = (B-A) * (B-A) + (b-a) * (b-a);
    k2 = (C-B)*(C-B) + (c-b)*(c-b);
    k3 = (A-C)*(A-C) + (a-c)*(a-c);
    float s;
    s = max(k1, k2);
    s = max(s, k3);


    if (k1+k2 == s) {
        flag = true;
    }
    if (k2+k3 == s) flag = true;
    if (k3+k1 == s) flag = true;

    if (flag) cout << "Yes";
    else cout << "No";
    
}