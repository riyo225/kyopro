#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int N = 1000, M = 1000;
    
    ofstream output("output.txt"); // 出力先ファイルを開く

    output << N << " " << M << endl;

    for (int i = 0; i < N-1; i++) {
        output << i << " " << i+1 << " " << 100000 << endl;
    }

    output.close(); // ファイルを閉じる
    return 0;
}
