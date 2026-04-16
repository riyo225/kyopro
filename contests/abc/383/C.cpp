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

int h, w, d;
char s[1009][1009];
int ans = 0;
int dist[1009][1009];
vector<pair<int, int>> humid;
queue<pair<int, int>> que;

int main() {
    cin >> h >> w >> d;
    rrep(i, h) {
        rrep(j, w) {
            cin >> s[i][j];
        }
    }

    rrep(i, h) {
        rrep(j, w) {
            dist[i][j] = -1;
        }
    }

    rrep(i, h) {
        rrep(j, w) {
            if (s[i][j] == 'H') {
                que.push(make_pair(i, j));
                dist[i][j] = 0;
            }
        }
    }

    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;

        que.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (dist[nx][ny] != -1) continue;
            if (nx <= 0 || nx > h || ny <= 0 || ny > w) continue;
            if (s[nx][ny] == '#') continue;

            dist[nx][ny] = dist[x][y] + 1;
            que.push(make_pair(nx, ny));
        }
    }


    rrep(i, h) {
        rrep(j, w) {
            if (dist[i][j] <= d && dist[i][j] != -1) {
                ans++;
            }
            cout << dist[i][j] <<  " ";
        }
        cout << endl;
    }
    

    cout << ans << endl;

    return 0;
}