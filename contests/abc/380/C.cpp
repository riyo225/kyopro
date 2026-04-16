#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
// sortmacro
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define GT greater<int>()
// priority_queue
#define VG vector<int>, greater<int>

// variables
int n, k;
string s;

int st = 0;
int cnt = 0;

bool fl = false;

vector<int> vst;
vector<int> ved;

string a, b, c, d;

int main() {
    cin >> n >> k >> s;
    
    rep(i, n) {
        if (!fl) {
            if (s[i] == '1') {
                st = i;
                fl = true;
            }
        }
        if (fl) {
            if (s[i] == '0') {
                cnt++;
                vst.push_back(st);
                ved.push_back(i-1);
                fl = false;
            }
            if (i == n-1) {
                cnt++;
                vst.push_back(st);
                ved.push_back(i);
                fl = false;
            }
        }
        if (cnt == k) {
            break;
        }
    }

    a = s.substr(0, ved[k-2]+1);
    b = s.substr(ved[k-2]+1, vst[k-1]-ved[k-2]-1);
    c = s.substr(vst[k-1], ved[k-1]-vst[k-1]+1);
    d = s.substr(ved[k-1]+1, n-ved[k-1]-1);

    cout << a+c+b+d << endl;
    return 0;
}