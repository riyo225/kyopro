#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define each(x, a) for (auto& x : a)
#define each2(a, b, c) for (auto& [a, b] : c)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) ((int)(x).size())
constexpr ll INF = (1LL << 60);
constexpr int INT_INF = (1 << 30);

int main() {
    string s;
    cin >> s;
    string a, b;
    a = s.substr(0, 2);
    b = s.substr(2, 2);
    if (a >= "01" && a <= "12") {
        if (b >= "01" && b <= "12") {
            cout << "AMBIGUOUS" << endl;
        }
        else if (b >= "01" && b <= "99") {
            cout << "MMYY" << endl;
        } 
        else {
            cout << "NA" << endl;
        }
    }
    else if (a >= "01" && a <= "99") {
        if (b >= "01" && b <= "12") {
            cout << "YYMM" << endl;
        }
        else if (b >= "01" && b <= "99") {
            cout << "AMBIGUOUS" << endl;
        }
        else {
            cout << "NA" << endl;
        }
    }
    else {
        cout << "NA" << endl;
    }
    return 0;
}