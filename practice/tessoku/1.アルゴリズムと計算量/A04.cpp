#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int n; 
    cin >> n;

    bitset<10> bs(n);
    cout << bs << endl;
}

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     for (int i = 9; i >= 0; i--) {
//         int wari = (1 << i);
//         if (n >= wari) {
//             n -= wari;
//             cout << 1;
//         }
//         else cout << 0;
//     }
//     cout << endl;
//     return 0;
// }