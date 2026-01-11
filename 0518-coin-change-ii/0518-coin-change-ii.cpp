class Solution {
public:
    int helper(int n, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (n == 0) {
            if (amount % coins[0] == 0)
                return 1;
            else
                return 0;
        }

        if (dp[n][amount] != -1)
            return dp[n][amount];

        int notTake = helper(n - 1, amount, coins, dp);

        int take = 0;
        if (coins[n] <= amount) {
            take = helper(n, amount - coins[n], coins, dp);
        }

        return dp[n][amount] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return helper(n - 1, amount, coins, dp);
    }
};
