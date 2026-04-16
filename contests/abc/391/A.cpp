#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i <= (int)(n); i++)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
constexpr ll INF = (1LL << 60);

int main() {
    string d;
    cin >> d;

    if (d[0] == 'N') cout << 'S';
    else if (d[0] == 'S') cout << 'N';
    
    if (d[0] == 'E' || d[1] == 'E') cout << 'W';
    else if (d[0] == 'W' || d[1] == 'W') cout << 'E';
    cout << endl;

    return 0;
}