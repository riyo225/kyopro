// [prefix: nibutan]

// ok が満たす条件
auto check = [&](ll mid) -> bool {
};

ll ok = 2e18;
ll ng = -1;


while (abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;

    if (check(mid)) {
        ok = mid;
    }
    else {
        ng = mid;
    }
}

cout << ok << nl;