// [prefix: dll]

struct DLL {
    vector<ll> prv, nxt;

    DLL(ll n) : prv(n + 1, -1), nxt(n + 1, -1) {}

    void insert_after(ll x, ll y) {
        ll z = nxt[x];
        
        nxt[x] = y;
        prv[y] = x;
        nxt[y] = z;
        if (z != -1) prv[z] = y;
    }

    void erase(ll x) {
        ll p = prv[x];
        ll z = nxt[x];

        if (p != -1) nxt[p] = z;
        if (z != -1) prv[z] = p;

        prv[x] = -1;
        nxt[x] = -1;
    }
};