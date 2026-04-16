#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int h[200009];
stack<int> st;
vector<int> ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];

    for (int i = n; i > 1; i--) {
        if (i == n) st.push(h[i]);
        else {
            if (st.top() > h[i]) {
                st.push(h[i]);
            }
            else {
                while (st.top() <= h[i]) {
                    st.pop();
                    if (st.empty()) break;
                }
                st.push(h[i]);
            }
        }
        ans.push_back(st.size());
    }

    reverse(ans.begin(), ans.end());
    ans.push_back(0);

    for (auto c : ans) cout << c << " ";
    cout << endl;
    return 0;
}