class Solution {
public:
    bool helper(int n, int k, vector<vector<int>>& dp, vector<int>& nums) {
        if (k == 0) return true;
        if (n == 0) return false;

        if (dp[n][k] != -1) return dp[n][k];

        bool notTake = helper(n - 1, k, dp, nums);
        bool take = false;

        if (nums[n - 1] <= k) {
            take = helper(n - 1, k - nums[n - 1], dp, nums);
        }

        return dp[n][k] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int x : nums) sum += x;

        if (sum % 2 != 0) return false;
        int k = sum / 2;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return helper(n, k, dp, nums);
    }
};
