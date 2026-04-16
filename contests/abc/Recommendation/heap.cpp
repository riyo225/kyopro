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

int n;
vector<int> a;
vector<int> hp;
vector<pair<int, int>> p;

void heapify(vector<int>& v, int size, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= size && v[left] > v[largest]) {
        largest = left;
    }
    if (right <= size && v[right] > v[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(v[i], v[largest]);
        p.push_back(make_pair(v[i], v[largest]));
        heapify(v, size, largest);
    }
}

void heapSort(vector<int>& v) {
    int size = v.size() - 1;

    for (int i = size / 2; i >= 1; i--) {
        heapify(v, size, i);
    }

    for (int i = size; i >= 2; i--) {
        swap(v[1], v[i]);
        p.push_back(make_pair(v[1], v[i]));
        heapify(v, i-1, 1);
    }


}

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1); // a[0]は使わないのでn + 1サイズにする
    rrep(i, n) {
        cin >> a[i];
    }

    heapSort(a);

    // 交換履歴の出力
    if (p.size() == 0) {
        cout << 0 << endl;
    } else {
        for (const auto& swap_pair : p) {
            cout << swap_pair.first << " " << swap_pair.second << endl;
        }
    }
    
    return 0;
}