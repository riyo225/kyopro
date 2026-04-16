// [prefix: swag]

template <class Monoid>
struct SwagQueue {
    using T = typename Monoid::Type;
    // front: 削除, back: 追加
    // first: 値, second: 演算結果
    stack<pair<T, T>> front, back;

    SwagQueue() {}

    ll size() const { return ll(front.size() + back.size()); }
    bool empty() const { return front.empty() && back.empty(); }

    void push(T val) {
        if (back.empty()) {
            back.push({val, Monoid::op(Monoid::e(), val)});
        }
        else {
            back.push({val, Monoid::op(back.top().second, val)});
        }
    }

    void pop() {
        if (front.empty()) {
            while (!back.empty()) {
                T val = back.top().first;
                back.pop();
                T aggregate = val;
                if (!front.empty()) {
                    aggregate = Monoid::op(val, front.top().second);
                }
                front.push({val, aggregate});
            }
        }
        if (!front.empty()) front.pop();
    }

    T fold () {
        if (empty()) return Monoid::e();
        if (front.empty()) return back.top().second;
        if (back.empty()) return front.top().second;
        return Monoid::op(front.top().second, back.top().second);
    }
};