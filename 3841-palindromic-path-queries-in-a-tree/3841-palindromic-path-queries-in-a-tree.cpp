#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> tin, tout, head, p, dep, sz, heavy, pos;
    vector<int> tree;
    int timer;

    void dfs1(int u, int parent, int d) {
        dep[u] = d;
        p[u] = parent;
        sz[u] = 1;
        int max_sz = 0;
        for (int v : adj[u]) {
            if (v != parent) {
                dfs1(v, u, d + 1);
                sz[u] += sz[v];
                if (sz[v] > max_sz) {
                    max_sz = sz[v];
                    heavy[u] = v;
                }
            }
        }
    }

    void dfs2(int u, int h) {
        head[u] = h;
        pos[u] = ++timer;
        if (heavy[u] != -1) {
            dfs2(heavy[u], h);
        }
        for (int v : adj[u]) {
            if (v != p[u] && v != heavy[u]) {
                dfs2(v, v);
            }
        }
    }

    void update_tree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update_tree(2 * node, start, mid, idx, val);
        else update_tree(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    int query_tree(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return query_tree(2 * node, start, mid, l, r) ^ query_tree(2 * node + 1, mid + 1, end, l, r);
    }

    int query_path(int u, int v) {
        int res = 0;
        while (head[u] != head[v]) {
            if (dep[head[u]] > dep[head[v]]) swap(u, v);
            res ^= query_tree(1, 1, n, pos[head[v]], pos[v]);
            v = p[head[v]];
        }
        if (dep[u] > dep[v]) swap(u, v);
        res ^= query_tree(1, 1, n, pos[u], pos[v]);
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        adj.assign(n, vector<int>());
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        tin.resize(n); tout.resize(n); head.resize(n); p.resize(n);
        dep.resize(n); sz.resize(n); heavy.assign(n, -1); pos.resize(n);
        tree.assign(4 * n + 1, 0);
        timer = 0;

        dfs1(0, -1, 0);
        dfs2(0, 0);

        for (int i = 0; i < n; ++i) {
            update_tree(1, 1, n, pos[i], 1 << (s[i] - 'a'));
        }

        vector<bool> ans;
        for (auto& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                update_tree(1, 1, n, pos[u], 1 << (c - 'a'));
            } else {
                int u, v;
                ss >> u >> v;
                int mask = query_path(u, v);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};