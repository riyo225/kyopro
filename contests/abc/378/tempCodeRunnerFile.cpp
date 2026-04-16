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
int h, w, k;
char s[19][19];
bool visited[19][19];
int m[19][19];

void dfs(int x, int y, int M) {
    visited[x][y] = true;
    m[x][y] = max(m[x][y], M);
    if (m[x][y] < k) {
        if (s[x+1][y] == '.') {
            int nx = x+1;
            int ny = y;
            if (!visited[nx][ny]) dfs(nx, ny, M+1);
        }
        if (s[x-1][y] == '.') {
            int nx = x-1;
            int ny = y;
            if (!visited[nx][ny]) dfs(nx, ny, M+1);
        }
        if (s[x][y+1] == '.') {
            int nx = x;
            int ny = y+1;
            if (!visited[nx][ny]) dfs(nx, ny, M+1);
        }
        if (s[x][y-1] == '.') {
            int nx = x;
            int ny = y-1;
            if (!visited[nx][ny]) dfs(nx, ny, M+1);
        }
    }
    return;
}

int main() {
    cin >> h >> w >> k;
    rrep(i, h) {
        rrep(j, w) {
            cin >> s[i][j];
        }
    }

    rrep(i, h) {
        rrep(j, w) {
            if (s[i][j] == '.') {
                dfs(i, j, 0);
            }
        }
    }
    
    int cnt = 0;
    rrep(i, h) {
        rrep(j, w) {
            if (m[i][j] == k) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}