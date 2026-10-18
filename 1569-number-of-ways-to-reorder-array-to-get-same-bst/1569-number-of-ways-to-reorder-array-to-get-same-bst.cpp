#include <vector>
#include <vector>

class Solution {
    long long MOD = 1e9 + 7;
    std::vector<std::vector<long long>> table;

    long long dfs(std::vector<long long>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        std::vector<long long> left, right;
        long long root = nums[0];
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] < root) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long leftWays = dfs(left) % MOD;
        long long rightWays = dfs(right) % MOD;

        long long ways = table[left.size() + right.size()][left.size()];
        ways = (ways * leftWays) % MOD;
        ways = (ways * rightWays) % MOD;

        return ways;
    }

public:
    int numOfWays(std::vector<int>& nums) {
        int n = nums.size();
        table.resize(n + 1, std::vector<long long>(n + 1, 1));
        
        // Precompute combinations using Pascal's Triangle
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
            }
        }

        std::vector<long long> v(nums.begin(), nums.end());
        return (dfs(v) - 1 + MOD) % MOD; // Subtract 1 to exclude the original array ordering
    }
};