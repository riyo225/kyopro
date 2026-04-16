#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string func(ll x, ll base) {
    if (x == 0) return "0";
    string res;
    while (x > 0) {
        res.push_back('0' + x % base);
        x /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool kaibun(const string& s) {
    int l = 0, r = (int)s.size() - 1;
    while (l < r) if (s[l++] != s[r--]) return false;
    return true;
}

string seisei(const string& s, ll n) {
    string t = s;
    reverse(t.begin(), t.end());
    return (n % 2 == 0) ? s + t : s + t.substr(1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, n;
    cin >> a >> n;

    ll m = n, cnt = 0;
    while (m > 0) {
        m /= 10;
        cnt++;
    }

    vector<ll> ten = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000};
    vector<ll> nine = {9,99,999,9999,99999,999999};

    ll ans = 0;

    for (ll i = 1; i < cnt; i++) {
        ll half_len = (i + 1) / 2;
        for (ll k = ten[half_len - 1]; k <= nine[half_len - 1]; k++) {
            ll pal_num = stoll(seisei(to_string(k), i));
            if (kaibun(func(pal_num, a))) ans += pal_num;
        }
    }

    {
        ll half_len = (cnt + 1) / 2;
        string s = to_string(n);
        ll end = stoll(s.substr(0, half_len));
        for (ll k = ten[half_len - 1]; k <= end; k++) {
            ll pal_num = stoll(seisei(to_string(k), cnt));
            if (pal_num > n) break;
            if (kaibun(func(pal_num, a))) ans += pal_num;
        }
    }

    cout << ans << "\n";
    return 0;
}
