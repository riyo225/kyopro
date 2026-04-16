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
int n, q;
vector<int> vec;
unordered_map<int, int> m;

void debug() {
    // vecの状態を表示
    cout << "vec: ";
    for (int i = 1; i <= n; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    // mの状態を表示
    cout << "m: ";
    for (const auto& p : m) {
        cout << p.first << "->" << p.second << " ";
    }
    cout << endl;
}

int main() {
    cin >> n >> q;
    vec.resize(n+1);

    for (int i = 1; i <= n; i++) {
        vec[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        m[i] = i;
    }

    rrep(i, q) {
        int one;
        cin >> one;
        if (one == 1) {
            int a, b;
            cin >> a >> b;

            vec[a] = b;
            m[a] = b;
        }
        else if (one == 2) {
            // cout << "============-" << endl;
            int a, b;
            cin >> a >> b;

            for (int i = 1; i <= n; i++) {
                if (vec[i] == a) {
                    vec[i] = b;
                    m[i] = b;
                }
                else if (vec[i] == b) {
                    vec[i] = a;
                    m[i] = a;
                }
            }

            // swap(vec[a], vec[b]);
        }
        else {
            int a;
            cin >> a;
            cout << m[a] << endl;
        }
        // debug();
    }

    return 0;
}
