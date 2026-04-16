#include <bits/stdc++.h>
using namespace std;

// --- グローバル定数 ---
const long long DX_4[] = {1, 0, -1, 0};
const long long DY_4[] = {0, 1, 0, -1};
// const int DX_8[] = {1, 0, -1, 0, 1, 1, -1, -1}; 
// const int DY_8[] = {0, 1, 0, -1, 1, -1, 1, -1};

// --- グローバル変数 ---
long long H;
long long W;
vector<vector<long long>> field;
vector<vector<bool>> seen;

// O(V + E)
void dfs_count_islands_internal(
    long long h, long long w,
    long long num_directions,
    const long long dx_arr[],
    const long long dy_arr[]
) {
    seen[h][w] = true;

    for (long long i = 0; i < num_directions; i++) {
        long long nh = h + dx_arr[i];
        long long nw = w + dy_arr[i];

        // 境界チェック
        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
        // 障害物チェック
        if (field[nh][nw] == 0) continue;
        // 訪問済みチェック
        if (seen[nh][nw]) continue;

        dfs_count_islands_internal(nh, nw, num_directions, dx_arr, dy_arr);
    }
}

void run_dfs_count_islands_internal(
    long long start_h, long long start_w,
    long long num_directions,
    const long long dx_arr[],
    const long long dy_arr[]
) {
    // --- 初期化 ---
    cin >> H >> W;
    field.resize(H);
    seen.assign(H, vector<bool> (W, false));
    for (long long i = 0; i < H; i++) {
        for (long long j = 0; j < W; j++) {
            cin >> field[i][j];
        }
    }

    long long island_count = 0;

    for (long long i = 0; i < H; i++) {
        for (long long j = 0; j < W; j++) {
            if (field[i][j] == 0) continue;
            if (seen[i][j]) continue;

            dfs_count_islands_internal(i, j, 8, dx_arr, dy_arr);
            island_count++;
        }
    }
    dfs_count_islands_internal(H, W, 4, DX_4, DY_4);
}