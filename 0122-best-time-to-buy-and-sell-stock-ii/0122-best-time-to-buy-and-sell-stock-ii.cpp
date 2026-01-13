class Solution {
public:
    long helper(vector<int>& prices, int ind, int buy, int n,
                vector<vector<long>>& dp) {
        if (ind == n) return 0;

        if (dp[ind][buy] != -1) return dp[ind][buy];

        long profit = 0;

        if (buy == 0) {
            profit = max(
                helper(prices, ind + 1, 0, n, dp),
                -prices[ind] + helper(prices, ind + 1, 1, n, dp)
            );
        } else {
            profit = max(
                helper(prices, ind + 1, 1, n, dp),
                prices[ind] + helper(prices, ind + 1, 0, n, dp)
            );
        }

        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n, vector<long>(2, -1));
        return helper(prices, 0, 0, n, dp);
    }
};
