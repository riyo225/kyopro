// [prefix: rotate]

// (i, j) -> (j, h-1-i)
template <typename T>
vector<vector<T>> rotate90(const vector<vector<T>>& a) {
    if (a.empty()) return {};
    ll h = a.size(), w = a[0].size();
    vector<vector<T>> res(w, vector<T> (h));
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) res[j][h - 1 - i] = a[i][j];
    }
    return res;
}
template <typename T>
vector<string> rotate90(const vector<string>& a) {
    if (a.empty()) return {};
    ll h = a.size(), w = a[0].size();
    vector<string> res(w, string(h, '.'));
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++)  res[j][h - 1 - i] = a[i][j];
    }
    return res;
}

// (i, j) -> (i, w-1-j)
template <typename T>
void flip_h(vector<T>& a) {
    for (auto& row : a) reverse(all(row));
}

// (i, j) -> (h-1-i, j)
template <typename T>
void flip_v(vector<T>& a) {
    reverse(all(a));
}

// (i, j) -> (j, i)
template <typename T>
vector<vector<T>> transpose(const vector<vector<T>>& a) {
    if (a.empty()) return {};
    ll h = ll(a.size()), w = ll(a[0].size());
    vector<vector<T>> res(w, vector<T> (h));
    for (ll i = 0; i < h; i++) {
        for (ll j = 0; j < w; j++) res[j][i] = a[i][j];
    }
    return res;
}