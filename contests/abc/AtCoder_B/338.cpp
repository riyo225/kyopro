#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    vector<int> alph(26, 0);
    int res = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        int j = c;
        alph[j-97]++;
    }

    for (int i = 0; i < 26; i++) {
       if (res < alph[i]) {
        res = alph[i];
        ans = i;
       }
    }
    ans += 97;
    char ansans = ans;
    cout << ansans << endl;
}