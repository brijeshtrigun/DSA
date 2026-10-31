class Solution {
public:
    int count(int i, int j,  vector<vector<int>> & dp, vector<vector<int>> & obstacles){
    if(i == 0 && j== 0) return obstacles[0][0] == 1 ? 0 : 1;
    if(i < 0 || j < 0) return 0;
    if(i >= 0 && j >= 0 && obstacles[i][j] == 1) return 0;
    if(dp[i][j] != -1) return dp[i][j];
        int up = count(i-1, j,  dp, obstacles);
        int left = count(i, j-1, dp, obstacles);
            return dp[i][j] = up+left;
    }
   
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return count(m-1, n-1,  dp, obstacleGrid);
    }
};