class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp){
        int m = grid.size();
        if(i == m-1){
            return grid[i][j];
        }
        if(dp[i][j] != INT_MIN) return dp[i][j];
        int down =  solve(grid, i+1, j, dp);
        int diagonal = solve(grid, i+1,  j+1, dp);
        return dp[i][j] = grid[i][j] + min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m , INT_MIN));
        return solve(triangle, 0, 0, dp);
    }
};