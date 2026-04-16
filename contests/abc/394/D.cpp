#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

string s;
queue<string> q;
bool ans = true;

int main() {
    cin >> s;
    q.push(s);

    while (!q.empty()) {
        string t = q.front();
        q.pop();
        int a = t.size();

        vector<int> idx;
        for (int i = t.size(); i > 0; i--) {
            if (t[i-1] == '(' && t[i] == ')' || t[i-1] == '<' && t[i] == '>' || t[i-1] == '[' && t[i] == ']') {
                t.erase(i-1, 2);
            }
        }
        if (t != "") {
            q.push(t);
        }

        if (a == t.size()) {
            ans = false;
            break;
        }
    }

    yes_no(ans);
    
    return 0;
}