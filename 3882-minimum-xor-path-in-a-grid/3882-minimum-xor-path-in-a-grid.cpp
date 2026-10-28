#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int minCost(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[i][j] stores all possible XOR values to reach cell (i, j)
        std::vector<std::vector<std::unordered_set<int>>> dp(m, std::vector<std::unordered_set<int>>(n));
        
        dp[0][0].insert(grid[0][0]);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int val : dp[i][j]) {
                    // Move right
                    if (j + 1 < n) {
                        dp[i][j + 1].insert(val ^ grid[i][j + 1]);
                    }
                    // Move down
                    if (i + 1 < m) {
                        dp[i + 1][j].insert(val ^ grid[i + 1][j]);
                    }
                }
            }
        }
        
        int min_xor = *std::min_element(dp[m - 1][n - 1].begin(), dp[m - 1][n - 1].end());
        return min_xor;
    }
};