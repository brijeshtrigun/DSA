class Solution {
public:
    int count(int i, int j, int total, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) {
            return 1;
        }
        if (i < 0 || j < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        int up = count(i, j - 1, total + 1, dp);
        int left = count(i - 1, j, total + 1, dp);
        return dp[i][j] = (up + left);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return count(m - 1, n - 1, 0, dp);
    }
};