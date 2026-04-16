#include <bits/stdc++.h>
using namespace std;

string s;
int sum = 0;

int main() {
    cin >> s;
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') num = i;
    }


    for (int j = 1; j < 26; j++) {
        char st = 'A' + j;
        for (int i = 0; i < s.size(); i++) {
            if (st == s[i]) {
                sum += abs(i - num);
                num = i;
            }
        }
    }

    cout << sum << endl;
    return 0;
}