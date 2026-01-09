class Solution {
public:
    int helper(int day, int last, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        if (day == 0) {
            int maxi = 0;
            for (int i = 0; i < 3; i++) {
                if (i != last) {
                    maxi = max(maxi, arr[0][i]);
                }
            }
            return maxi;
        }

        if (dp[day][last] != -1) return dp[day][last];

        int maxi = 0;
        for (int i = 0; i < 3; i++) {
            if (i != last) {
                int points = arr[day][i] + helper(day - 1, i, arr, dp);
                maxi = max(maxi, points);
            }
        }
        return dp[day][last] = maxi;
    }

    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return helper(n - 1, 3, arr, dp);
    }
};
