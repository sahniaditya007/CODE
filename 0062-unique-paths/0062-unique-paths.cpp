class Solution {
public:
    int helper(int m, int n, vector<vector<int>>& dp) {
        if (m == 0 || n == 0) return 1;

        if (dp[n][m] != -1) return dp[n][m];

        return dp[n][m] = helper(m - 1, n, dp) + helper(m, n - 1, dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(m - 1, n - 1, dp);
    }
};
