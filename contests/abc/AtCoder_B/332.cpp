#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int k, g, m; cin >> k >> g >> m;
    int g_am = 0, m_am = 0;

    for (int i = 0; i < k; i++) {
        if (g_am == g) {
            g_am = 0;
        }
        else if (m_am == 0) {
            m_am += m;
        }
        else {
            if (g <= m_am) {
                m_am -= (g-g_am);
                g_am = g;
            }
            else {
                g_am += m_am;
                m_am = 0;
            }
        }
    }       
    cout << g_am << " " << m_am << endl;
}