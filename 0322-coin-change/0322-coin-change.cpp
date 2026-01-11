class Solution {
public:
    int helper(int n, vector<vector<int>>& dp, vector<int>& coins, int amount) {
        if (n == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            else
                return 1e9;
        }

        if (dp[n][amount] != -1)
            return dp[n][amount];

        int notTake = helper(n - 1, dp, coins, amount);
        int take = 1e9;

        if (coins[n] <= amount) {
            take = 1 + helper(n, dp, coins, amount - coins[n]);
        }

        return dp[n][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = helper(n - 1, dp, coins, amount);
        return ans >= 1e9 ? -1 : ans;
    }
};