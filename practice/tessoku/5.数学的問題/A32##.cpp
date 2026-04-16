// 三項演算子を使ったコードの書き方もある
#include <bits/stdc++.h>
using namespace std;

int n, a, b;
bool dp[100009];

int main() {
    cin >> n >> a >> b;

    dp[0] = false; // 初期状態。0は負けの状態
    
    for (int i = 1; i <= n; i++) {
        bool win_a = (i - a >= 0) ? !dp[i - a] : false;  // a個取った後に相手が負けるか
        bool win_b = (i - b >= 0) ? !dp[i - b] : false;  // b個取った後に相手が負けるか
        dp[i] = win_a || win_b;  // どちらかの方法で相手が負けるなら勝ちの状態にする
    }

    if (dp[n]) 
        cout << "First" << endl;  // 勝ちの状態
    else 
        cout << "Second" << endl; // 負けの状態
    
    return 0;
}
