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
int n, ans = 1;
int h[3009];
bool vec[3009][3009];

int main() {
    cin >> n;
    rrep(i, n) {
        cin >> h[i];
    }

    rrep(i, n) {
        rrep(j, n) {
            vec[i][j] = false;
        }
    }

    rrep(i, n) {
        for (int j = 1; j <= n-i; j++) {
            if (h[j] == h[j+i]) {
                vec[i][j] = true;
            }
        }
    }

    rrep(i, n) {
        for (int j = 1; j <= n-i; j++) {
            int cnt = 1;
            int pos = j;
            while (vec[i][pos] && pos <= n-i) {
                // cout << i << " " << pos << endl;
                pos += i;
                cnt++;
            }
            ans = max(cnt, ans);
        }
    }

    // rrep(i, n) {
    //     rrep(j, n) {
    //         if (vec[i][j]) {
    //             cout << 't' << " ";
    //         }
    //         else {
    //             cout << 'f' << " ";
    //         }
    //     }
    //     cout << endl;
    // }

    cout << ans << endl;
    return 0;
}