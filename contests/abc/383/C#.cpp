#include <bits/stdc++.h>
using namespace std;
a#include <bits/stdc++.h>
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
int h, w, d;
char s[1009][1009];
bool is_humid[1009][1009];
int ans = 0;
vector<pair<int, int>> humid;

void bfs(vector<pair<int, int>> v, int z) {
    rep(i, v.size()) {
        is_humid[v[i].first][v[i].second] = true;
        for (int dir = 0; dir < 4; dir++) {
            int nx = v[i].first + dx[dir];
            int ny = v[i].second + dy[dir];

            if (nx <= 0 || nx > h || ny <= 0 || ny > w) continue;
            if (s[nx][ny] == '#') continue;

            v.push_back(make_pair(nx, ny));
        } 
    }
    if (z-1 >= 0) {
        bfs(v, z-1);
    }
}

int main() {
    cin >> h >> w >> d;
    rrep(i, h) {
        rrep(j, w) {
            cin >> s[i][j];
        }
    }

    rrep(i, h) {
        rrep(j, w) {
            is_humid[i][j] = false;
        }
    }

    rrep(i, h) {
        rrep(j, w) {
            if (s[i][j] == 'H') {
                humid.push_back(make_pair(i, j));
            }
        }
    }

    bfs(humid, d);

    rrep(i, h) {
        rrep(j, w) {
            if (is_humid[i][j] == true) {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
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


int main() {


    return 0;
}