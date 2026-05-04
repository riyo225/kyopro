// [prefix: souhoukou, dll]

struct DoublyLinkedList {
    const ll HEAD_BASE = -1000000000LL;
    const ll TAIL_BASE = -2000000000LL;
    unordered_map<ll, ll> prv, nxt;

    ll head_id(ll i) { return HEAD_BASE - i; }
    ll tail_id(ll i) { return TAIL_BASE - i; }

    void link(ll a, ll b) {
        nxt[a] = b;
        prv[b] = a;
    }

    // n 個のからの列を作成
    DoublyLinkedList(ll n) {
        for (ll i = 0; i < n; i++) {
            link(head_id(i), tail_id(i));
        }
    }

    // 列 i の末尾に要素 x を追加
    void push_back(ll i, ll x) {
        ll t = tail_id(i);
        ll last_elem = prv[t];
        link(last_elem, x);
        link(x, t);
    }

    // 要素 x の後に y を挿入
    void insert_after(ll x, ll y) {
        ll z = nxt[x];
        link(x, y);
        link(y, z);
    }

    void erase(ll x) {
        link(prv[x], nxt[x]);
        prv[x] = -2e18; 
        nxt[x] = -2e18;
    }

    vector<ll> get_list(ll i) {
        vector<ll> res;
        ll cur = nxt[head_id(i)];
        while (cur != tail_id(i)) {
            res.push_back(cur);
            cur = nxt[cur];
        }
        return res;
    }
};