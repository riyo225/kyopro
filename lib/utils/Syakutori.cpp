// [prefix: syakutori]

ll r = 0;
ll sum = 0;
ll ans = 0;

// 条件を満たすとき、rを増やす
auto check = [&](ll l, ll r) -> bool {
};

for (ll l = 0; l < n; l++) {
    while (r < n && check(l, r)) {
        sum += a[r];
        r++;
    }

    // ans の更新
    chmax(ans, r - l);
    if (r == l) r++;
    else sum -= a[l];
}