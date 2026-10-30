#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    long long shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
        }

        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
        vector<vector<long long>> dist(n, vector<long long>(k + 1, -1));

        pq.push({0, 0, 1});
        dist[0][1] = 0;

        while (!pq.empty()) {
            auto [w, u, count] = pq.top();
            pq.pop();

            if (u == n - 1) {
                return w;
            }

            if (w > dist[u][count]) continue;

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                int next_count = (labels[v] == labels[u]) ? count + 1 : 1;

                if (next_count > k) continue;

                if (dist[v][next_count] == -1 || w + weight < dist[v][next_count]) {
                    dist[v][next_count] = w + weight;
                    pq.push({dist[v][next_count], v, next_count});
                }
            }
        }

        long long ans = -1;
        for (int c = 1; c <= k; ++c) {
            if (dist[n - 1][c] != -1) {
                if (ans == -1 || dist[n - 1][c] < ans) {
                    ans = dist[n - 1][c];
                }
            }
        }

        return ans;
    }
};