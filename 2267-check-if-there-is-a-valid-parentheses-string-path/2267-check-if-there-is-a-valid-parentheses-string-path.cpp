#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int m, n;
    int memo[100][100][101];

    bool solve(int r, int c, int bal, vector<vector<char>>& grid) {

        bal += (grid[r][c] == '(' ? 1 : -1);


        if (bal < 0) return false;


        if (r == m - 1 && c == n - 1) {
            return bal == 0;
        }


        if (memo[r][c][bal] != -1) {
            return memo[r][c][bal];
        }

        bool possible = false;


        if (r + 1 < m) {
            possible = possible || solve(r + 1, c, bal, grid);
        }

    
        if (c + 1 < n) {
            possible = possible || solve(r, c + 1, bal, grid);
        }

        return memo[r][c][bal] = possible;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

     
        if ((m + n - 1) % 2 != 0) return false;

     
        if (grid[0][0] != '(' || grid[m - 1][n - 1] != ')') return false;

   
        memset(memo, -1, sizeof(memo));

        return solve(0, 0, 0, grid);
    }
};