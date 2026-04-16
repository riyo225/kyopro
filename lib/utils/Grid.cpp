// [prefix: grid]

const ll dr[] = {1, 0, -1, 0}; const ll dc[] = {0, 1, 0, -1};
string DIRS = "DRUL";
const ll dr8[] = {1, 1, 0, -1, -1, -1, 0, 1}; const ll dc8[] = {0, 1, 1, 1, 0, -1, -1, -1};
auto is_inside = [&](ll r, l c) { return 0 <= r && r < h && 0 <= c && c < w; };
auto is_outside = [&](ll r, ll c) { return r < 0 || h <= r || c < 0 || w <= c; };
auto get_id = [&](ll r, ll c) { return r * w + c; };
auto get_2d = [&](ll id)  { return make_pair(id / w, id % w); };