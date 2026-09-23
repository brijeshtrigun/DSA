class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return dfs(grid, i, j);
                }
            }
        }

        return 0;
    }

private:
    int dfs(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        // Outside grid => one boundary edge
        if (i < 0 || i >= m || j < 0 || j >= n)
            return 1;

        // Water => one boundary edge
        if (grid[i][j] == 0)
            return 1;

        // Already visited
        if (grid[i][j] == 2)
            return 0;

        // Mark visited
        grid[i][j] = 2;

        return dfs(grid, i + 1, j)
             + dfs(grid, i - 1, j)
             + dfs(grid, i, j + 1)
             + dfs(grid, i, j - 1);
    }
};