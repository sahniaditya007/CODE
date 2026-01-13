class Solution {
public:
    int helper(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = helper(i - 1, j - 1, word1, word2, dp);

        return dp[i][j] = min({
            1 + helper(i, j - 1, word1, word2, dp),
            1 + helper(i - 1, j, word1, word2, dp),
            1 + helper(i - 1, j - 1, word1, word2, dp)
        });
    }

    int minDistance(string word1, string word2) {
        int i = word1.size();
        int j = word2.size();
        vector<vector<int>> dp(i, vector<int>(j, -1));
        return helper(i - 1, j - 1, word1, word2, dp);
    }
};
