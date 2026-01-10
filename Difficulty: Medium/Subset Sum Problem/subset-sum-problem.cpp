class Solution {
public:
    bool helper(int n, int sum, vector<vector<int>>& dp, vector<int>& arr) {
        if (sum == 0) return true;
        if (n == 0) return arr[0] == sum;

        if (dp[n][sum] != -1) return dp[n][sum];

        bool notTake = helper(n - 1, sum, dp, arr);
        bool take = false;

        if (arr[n] <= sum)
            take = helper(n - 1, sum - arr[n], dp, arr);

        return dp[n][sum] = take || notTake;
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return helper(n - 1, sum, dp, arr);
    }
};
