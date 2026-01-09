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
        if (n == 1) return nums[0];

        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> dp1(nums1.size(), -1);
        int ans1 = helper(nums1.size() - 1, nums1, dp1);

        vector<int> nums2(nums.begin() + 1, nums.end());
        vector<int> dp2(nums2.size(), -1);
        int ans2 = helper(nums2.size() - 1, nums2, dp2);

        return max(ans1, ans2);
    }
};
