// [prefix: for-while]

auto check = [&](ll l, ll r) -> bool {
    return true;
};

// 尺取り法みたいな for-while
ll r = 0;
for (ll l = 0; l < n; l++) {
    while (r < n && check(l, r)) {
        r++;
    }

    // 処理

    if (l == r) r++;
    // else sum -= a[l];
}

// 切り取る for-while
for (ll l = 0; l < n; ) {
    ll r = l + 1;
    while (r < n && check(l, r)) {
        r++;
    }

    // 処理

    l = r;
}