// [prefix: offline2dsum]

template <typename T>
struct BIT {
    ll n;
    vector<T> tree;

    BIT(ll n) : n(n), tree(n + 1, 0) {}

    void build(const vector<T>& a) {
        for (ll i = 0; i < n; i++) tree[i + 1] = a[i];
        for (ll i = 1; i <= n; i++) {
            ll j = i + (i & -i);
            if (j <= n) tree[j] += tree[i];
        }
    }

    void add(ll i, T x) {
        for (i++; i <= n; i += (i & -i)) tree[i] += x;
    }

    void update(ll i, T x) {
        add(i, x - get(i));
    }

    T query(ll i) {
        T s = 0;
        for (; i > 0; i -= i & -i) s += tree[i];
        return s;
    }

    T range_query(ll l, ll r) {
        if (l >= r) return 0;
        return query(r) - query(l);
    }

    T get(ll i) {
        return query(i + 1) - query(i);
    }
};

struct Offline2DPointSum {
    struct Point { ll x, y, w; };
    struct Query { ll xl, xr, yd, yu; ll id; };

    vector<Point> points;
    vector<Query> queries;

    void add_point(ll x, ll y, ll w = 1) { points.push_back({x, y, w}); }

    void add_query(ll xl, ll xr, ll yd, ll yu) { queries.push_back({xl, xr, yd, yu, (ll)queries.size()}); }

    vector<ll> solve() {
        // 座標圧縮
        vector<ll> ys;
        for (const auto& p : points) ys.push_back(p.y);
        for (const auto& q : queries) {
            ys.push_back(q.yd);
            ys.push_back(q.yu);
        }
        sort(all(ys));
        ys.erase(unique(all(ys)), ys.end());

        auto get_y = [&](ll y) -> ll {
            return lower_bound(all(ys), y) - ys.begin();
        };

        struct Event {
            ll x;
            ll type; // 0: 点, 1: クエリの端
            ll yd, yu, sign;
            ll w;
            ll id;
            bool operator<(const Event& o) const {
                if (x != o.x) return x < o.x;
                return type < o.type;
            }
        };

        vector<Event> events;
        for (const auto& p : points) {
            events.push_back({p.x, 0, get_y(p.y), -1, 1, p.w, -1});
        }
        for (const auto& q : queries) {
            events.push_back({q.xr, 1, get_y(q.yd), get_y(q.yu), 1, 0, q.id});
            events.push_back({q.xl - 1, 1, get_y(q.yd), get_y(q.yu), -1, 0, q.id});
        }

        sort(all(events));
        BIT<ll> bit(ys.size() + 5);
        vector<ll> ans(queries.size(), 0);

        for (const auto& e : events) {
            if (e.type == 0) {
                bit.add(e.yd, e.w);
            }
            else {
                ll sum = bit.range_query(e.yd, e.yu + 1);
                ans[e.id] += sum * e.sign;
            }
        }
        return ans;
    }
};