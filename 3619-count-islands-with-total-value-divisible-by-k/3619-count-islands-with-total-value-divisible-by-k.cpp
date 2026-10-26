#include <vector>

using namespace std;

class Solution {
private:
    void dfs(int r, int c, int m, int n, vector<vector<int>>& grid, long long& current_sum) {
        // Mark current cell as visited by setting it to 0
        current_sum += grid[r][c];
        grid[r][c] = 0;

        // 4-directional offsets: up, down, left, right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                dfs(nr, nc, m, n, grid, current_sum);
            }
        }
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int valid_islands_count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long current_sum = 0;
                    dfs(i, j, m, n, grid, current_sum);
                    
                    if (current_sum % k == 0) {
                        valid_islands_count++;
                    }
                }
            }
        }

        return valid_islands_count;
    }
};