// [prefix: nshinhou]

// 文字を数字に変換する（A->10）
auto c2l = [&](char c) -> ll {
    if ('0' <= c && c <= '9') return c - '0';
    if ('a' <= c && c <= 'z') return c - 'a' + 10;
    return c - 'A' + 10;
};

// 数字を文字に変換する（10->A）
auto l2c = [&](ll v) -> char {
    if (0 <= v && v <= 9) return (char)(v + '0');
    return (char)(v - 10 + 'A');
};

// n進法->10進法
auto base2long = [&](string s, ll base) -> ll {
    ll res = 0;
    for (char c : s) res = res * base + c2l(c);
    return res;
};

// 10進法->n進法
auto long2base = [&](ll val, ll base) -> string {
    if (val == 0) return "0";
    string res = "";
    while (val > 0) {
        res += l2c(val % base);
        val /= base;
    }
    reverse(all(res));
    return res;
};