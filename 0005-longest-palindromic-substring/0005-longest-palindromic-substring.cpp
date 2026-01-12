class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        int maxLen = 0;
        int endIdx = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == rev[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    if (dp[i][j] > maxLen && i - dp[i][j] == n - j) {
                        maxLen = dp[i][j];
                        endIdx = i - 1;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return s.substr(endIdx - maxLen + 1, maxLen);
    }
};
