
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        vector<long long> dp(n, 0);
        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            long long right = 0;

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    // Mirror: swap right and down paths
                    swap(right, dp[j]);
                }
                else {
                    // Normal cell: combine both directions
                    long long total = (right + dp[j]) % MOD;

                    right = total;
                    dp[j] = total;
                }
            }
        }

        return dp[n - 1];
    }
};
