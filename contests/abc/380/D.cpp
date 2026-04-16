#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define rrep(i, n) for (ll i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
// sortmacro
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define GT greater<int>()
// priority_queue
#define VG vector<int>, greater<int>

// variables
string s;
int q;
ll k[200009];

ll two[69];

tuple<ll, ll> rv(ll x, ll m, int cnt) {
    if (x <= two[1]) {
        return forward_as_tuple(x, cnt);
    }
    for (int i = 2; i <= 60; i++) {
        if (x <= two[i]) {
            ll st = two[i-1];
            x -= st;
            cnt++;
            break;
        }
    }
    if (x <= m) {
        return forward_as_tuple(x, cnt);
    }
    else {
        return rv(x, m, cnt);
    }
    return forward_as_tuple(0, 0);
}

int main() {
    cin >> s >> q;
    rrep(i, q) {
        cin >> k[i];
    }
    
    ll m = s.size();

    rrep(i, 60) {
        two[i] = m * pow(2, i-1);
    }

    rrep(i, q) {
        ll a, cnt;
        tie(a, cnt) = rv(k[i], m, 0);
        
        if (cnt % 2 == 0) {
            cout << s[a-1] << " ";
        }
        else {
            if (islower(s[a-1])) {
                char c = toupper(s[a-1]);
                cout << c << " ";
            }
            else {
                char c = tolower(s[a-1]);
                cout << c << " ";
            }
        }
    }
    
    return 0;
}