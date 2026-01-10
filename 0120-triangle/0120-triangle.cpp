class Solution {
public:
    int helper(int m, int n, vector<vector<int>>& dp,
               vector<vector<int>>& triangle) {

        int size = triangle.size();

        for (int j = 0; j < size; j++) {
            dp[size - 1][j] = triangle[size - 1][j];
        }

        for (int i = size - 2; i >= 0; i--) {
            for (int j = i; j >= 0; j--) {
                int d  = triangle[i][j] + dp[i + 1][j];
                int dg = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(d, dg);
            }
        }
        return dp[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return helper(0, 0, dp, triangle);
    }
};
