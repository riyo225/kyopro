#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int palindrome(string s, int start, int end) {
    int ans = end;
    while (start < end) {
        if (s[start] != s[end]) {
            end--;
            ans--;
            if (start != 0) {
                start--;
            }
        }
        else {
            start++;
            end--;
        }
    }
    return ans;
}               

int main() {
    string s;
    cin >> s;

    string t = s;
    reverse(t.begin(), t.end());
    int n = s.size();

    int ans = palindrome(t, 0, n-1);
    cout << ans << endl;
    cout << s.substr(0, n-ans-1) + t << endl;

    return 0;
}