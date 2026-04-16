#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int main() {
    ll n, k;
    string s;
    cin >> n >> k >> s;

    int ocnt = 0;
    rep(i, n) {
        if (s[i] == 'o') ocnt++;
    }
    for (int i = 0; i < n-1; i++) {
        if (s[i] == 'o') {
            if (s[i+1] == '?') {
                s[i+1] = '.';
            }
        }
    }
    for (int i = n-1; i > 0; i--) {
        if (s[i] == 'o') {
            if (s[i-1] == '?') {
                s[i-1] = '.';
            }
        }
    }

    int m = 0;
    string t = s;
    rep(i, n) {
        if (t[i] == '?') {
            if (i == 0 && t[i+1] != 'o') {
                t[i] = 'o';
                m++;
            }
            else if (t[i-1] != 'o') {
                t[i] = 'o';
                m++;
            }
        }
        else if (t[i] == 'o') {
            m++;
        }
    }

    // cout << m << " " << k << endl;
    // cout << s << endl;
    // cout << t << endl;

    if (m == k && ocnt != k) {
        rep(i, n) {
            int j = 0;
            while (s[i+j] == '?' && i+j < n) {
                j++;
            }
            if (j % 2 == 1) {
                for (int h = 0; h <= j; h++) {
                    if (h%2==0) {
                        s[i+h] = 'o';
                    }
                    else {
                        s[i+h] = '.';
                    }
                }
            }
            i+=j;
        }
    }
    if (ocnt == k) {
        rep(i, n) {
            if (s[i] == '?') {
                s[i] = '.';
            }
        }
    }


    cout << s << endl;
    
    return 0;
}