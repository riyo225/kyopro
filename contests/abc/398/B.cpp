#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

vector<int> a(7);
bool ans = false;

int main() {
    for (int i = 0; i < 7; i++) {
        cin >> a[i];
    }

    sort(all(a));

    for (int i = 0; i < 5; i++) {
        if (a[i] == a[i+1] && a[i] == a[i+2]) {
            for (int j = 0; j < 6; j++) {
                if (a[j] == a[j+1] && a[i] != a[j]) {
                    ans = true;
                }
            }
        }
    }

    yes_no(ans);
    
    return 0;
}
