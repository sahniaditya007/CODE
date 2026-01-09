class Solution {
public:
    int helper(int n, vector<int>& nums, vector<int>& dp) {
        if (n < 0) return 0;
        if (n == 0) return nums[0];

        if (dp[n] != -1) return dp[n];

        int pick = nums[n] + helper(n - 2, nums, dp);
        int notpick = helper(n - 1, nums, dp);

        return dp[n] = max(pick, notpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, -1);
        return helper(n - 1, nums, dp);
    }
};
