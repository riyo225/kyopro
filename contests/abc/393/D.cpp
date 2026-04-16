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
    ll n;
    string s;
    // cin >> n >> s;
    cin >> s;
    n = s.size();

    ll k = 0;
    for (int i = 0; i < n; i++) {
        int j = 0;
        if (s[i] == '1') {
            while (s[i+j] == '1' && i+j < n) {
                j++;
            }
            k++;
        }
        i+=j;
    }
    
    if (k == 1) {
        cout << 0 << endl;
        return 0;
    }

    ll sum = 0;
    ll cnt = 0;
    rep(i, n) {
        if (s[i] == '1') {
            sum += i;
            cnt += 1;
        }
    }
    ll ctr = sum / cnt;
    ll ans = 0;
    ll l = -1, r = n;
    ll lcnt = 0, rcnt = 0;
    for (int i = 0; i <= ctr; i++) {
        if (s[i] == '0') l = i;
        if (s[i] == '1') lcnt++; 
    }
    for (int i = n-1; i >= ctr+1; i--) {
        if (s[i] == '0') r = i;
        if (s[i] == '1') rcnt++;
    }

    for (int i = ctr; i >= 0; i--) {
        // cout << l << endl;
        if (s[i] == '1' && l > i) {
            ans += (l - i);
            s[i] = '0';
            s[l] = '1';
            while (s[l] == '1') {
                l--;
            }
        }
    }
    // cout << ans << endl;
    // cout << "------" << endl;
    for (int i = ctr+1; i < n; i++) {
        // cout << r << endl;
        if (s[i] == '1' && r < i) {
            ans += (i - r);
            s[i] = '0';
            s[r] = '1';
            while (s[r] == '1') {
                r++;
            }
        } 
    }

    // cout << s << endl;
    cout << ans << endl;

    return 0;
}