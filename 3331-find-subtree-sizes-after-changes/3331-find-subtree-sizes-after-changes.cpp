class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = static_cast<int>(parent.size());
        vector<vector<int>> orig_adj(n);
        for (int i = 1; i < n; ++i) {
            orig_adj[parent[i]].push_back(i);
        }

        vector<int> new_parent(n, -1);
        vector<int> last_seen(26, -1);

        auto dfs1 = [&](auto& self, int u) -> void {
            int c = s[u] - 'a';
            if (u > 0) {
                new_parent[u] = (last_seen[c] != -1) ? last_seen[c] : parent[u];
            }
            int prev = last_seen[c];
            last_seen[c] = u;
            for (int v : orig_adj[u]) {
                self(self, v);
            }
            last_seen[c] = prev;
        };

        dfs1(dfs1, 0);

        vector<vector<int>> final_adj(n);
        for (int i = 1; i < n; ++i) {
            final_adj[new_parent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        auto dfs2 = [&](auto& self, int u) -> int {
            int total = 1;
            for (int v : final_adj[u]) {
                total += self(self, v);
            }
            return ans[u] = total;
        };

        dfs2(dfs2, 0);
        return ans;
    }
};