class Solution {
private:
    int rows, cols;
    
    void dfs(int r, int c, vector<vector<int>>& grid) {
        // Check boundaries and water cells (1)
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 1) {
            return;
        }
        
        // Mark the current land cell as visited/water so we don't process it again
        grid[r][c] = 1;
        
        // Traverse all 4 directions
        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        // Step 1: Flood-fill all 0s connected to the top and bottom borders
        for (int c = 0; c < cols; ++c) {
            if (grid[0][c] == 0) dfs(0, c, grid);
            if (grid[rows - 1][c] == 0) dfs(rows - 1, c, grid);
        }
        
        // Step 2: Flood-fill all 0s connected to the left and right borders
        for (int r = 0; r < rows; ++r) {
            if (grid[r][0] == 0) dfs(r, 0, grid);
            if (grid[r][cols - 1] == 0) dfs(r, cols - 1, grid);
        }
        
        // Step 3: Count the remaining valid closed islands
        int closedIslandsCount = 0;
        for (int r = 1; r < rows - 1; ++r) {
            for (int c = 1; c < cols - 1; ++c) {
                if (grid[r][c] == 0) {
                    closedIslandsCount++;
                    dfs(r, c, grid); // Sink this entire closed island
                }
            }
        }
        
        return closedIslandsCount;
    }
};