#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define each(x, a) for (auto& x : a)
#define each2(a, b, c) for (auto& [a, b] : c)
#define yes_no(ans) cout << ((ans) ? "Yes" : "No") << endl;
#define YES_NO(ans) cout << ((ans) ? "YES" : "NO") << endl;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) ((int)(x).size())
const string alpha = "abcdefghijklmnopqrstuvwxyz";
const string ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr ll INF = (1LL << 60);
constexpr int INT_INF = (1 << 30);

// sub : k個のビットが立っている組み合わせ
// next_combination : 辞書順で次に大きいk個のビットが立っている組み合わせを求める
// O(nCk)
// 「サイズ k の部分集合だけを高速に列挙したい」
// 「部分和・重み付き問題などでサイズを固定して探索したい」

int next_combination(int sub) {
    // subの中で一番下の1bitを取り出す
    int x = sub & -sub;
    // 最下位のbit(x)を足して繰上りをする
    int y = sub + x;
    // ~y : bit反転
    // sub & ~y : subの中からyで立っているbitを取り除く
    // / x : それをxの位置に合わせて右詰め
    // >> 1 : 余分な繰上りをずらす
    // | y : yと合成して次の組み合わせをつくる
    return (((sub & ~y) / x) >> 1) | y;
}

int main() {
    int n = 5;
    int k = 3;

    // 0b00001000から1を引く
    int b = (1<<k)-1;
    for (; b < (1<<n); b = next_combination(b)) {

    }
    return 0;
}