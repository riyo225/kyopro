// [prefix: trie]

struct TrieNode {
    vector<ll> next;
    ll accept;
    ll count;

    TrieNode() {
        next.assign(26, -1);
        accept = 0;
        count = 0;
    }
};

struct Trie {
    vector<TrieNode> nodes;

    Trie() {
        nodes.push_back(TrieNode());
    }

    ll c2l(char c) {
        return c - 'a';
    }

    void insert(const string& word) {
        ll cur = 0;
        for (char c : word) {
            ll idx = c2l(c);
            
            if (nodes[cur].next[idx] == -1) {
                nodes[cur].next[idx] = nodes.size();
                nodes.push_back(TrieNode());
            }

            cur = nodes[cur].next[idx];
            nodes[cur].count++;
        }
        nodes[cur].accept++;
    }

    bool search(const string& word) {
        ll cur = 0;
        for (char c : word) {
            ll idx = c2l(c);
            if (nodes[cur].next[idx] == -1) {
                return false;
            }
            cur = nodes[cur].next[idx];
        }
        return nodes[cur].accept > 0;
    }

    ll count_prefix(const string& prefix) {
        ll cur = 0;
        for (char c : prefix) {
            ll idx = c2l(c);
            if (nodes[cur].next[idx] == -1) {
                return 0;
            }
            cur = nodes[cur].next[idx];
        }
        return nodes[cur].count;
    }

    ll get_max_lcp(const string& word) {
        ll cur = 0;
        ll res = 0;
        for (char c : word) {
            ll idx = c2l(c);
            cur = nodes[cur].next[idx];

            if (nodes[cur].count > 1) {
                res++;
            }
            else {
                break;
            }
        }
        return res;
    }
};