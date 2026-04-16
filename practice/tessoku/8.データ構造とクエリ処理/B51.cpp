#include <bits/stdc++.h>
using namespace std;

string s;
stack<int> st;

int main() {
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') st.push(i+1);
        if (s[i] == ')') {
            cout << st.top() << " " << i+1 << endl;
            st.pop();
        }
    }
    return 0;
}