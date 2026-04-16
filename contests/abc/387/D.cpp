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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// variables
int h, w;
string s[1009];
int dist[1009][1009];
queue<pair<int, int>> que;
bool flag[1009][1009];
bool f[1009][1009];

int main() {
    cin >> h >> w;
    rrep(i, h) {
        cin >> s[i];
    }

    rrep(i, h) {
        rrep(j, w) {
            dist[i][j] = -1;
        }
    }

    int a, b;

    rrep(i, h) {
        rep(j, w) {
            if (s[i][j] == 'S') {
                que.push(make_pair(i, j+1));
                dist[i][j+1] = 0;
            }
            if (s[i][j] == 'G') {
                a = i;
                b = j+1;
            }
        }
    }

    int x = que.front().first;
    int y = que.front().second;
    que.pop();

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx <= 0 || nx > h || ny <= 0 || ny > w) continue;
        if (s[nx][ny-1] == '#') continue;

        dist[nx][ny] = dist[x][y] + 1;

        que.push(make_pair(nx, ny));

        if (dx[dir] == 0) {
            flag[nx][ny] = true;
        } 
        else {
            flag[nx][ny] = false;
        }
    }

    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for (int dir = 0; dir < 4; dir++) {
            if (!f[x][y]) {
                if (flag[x][y] && dx[dir] == 0) {
                    continue;
                }
                if (!flag[x][y] && dx[dir] != 0) {
                    continue;
                }
            }
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (dist[nx][ny] != -1 && dist[nx][ny] < dist[x][y]+1) continue;
            if (nx <= 0 || nx > h || ny <= 0 || ny > w) continue;
            if (s[nx][ny-1] == '#') continue;

            dist[nx][ny] = dist[x][y] + 1;
            que.push(make_pair(nx, ny));

            if (dist[nx][ny] != -1 && flag[nx][ny] != !flag[x][y]) {
                f[nx][ny] = true;
            }
            f[nx][ny] = f[x][y];
            flag[nx][ny] = !flag[x][y];
            
        }

        rrep(i, h) {
            rrep(j, w) {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
        cout << "-------------------" << endl;

    }

    rrep(i, h) {
        rrep(j, w) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }

    cout << dist[a][b] << endl;

    return 0;
}