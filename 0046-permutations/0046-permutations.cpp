class Solution {
public:
    vector<vector<int>> ans;

    void helper(int i, vector<int>& nums) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int idx = i; idx < nums.size(); idx++) {
            swap(nums[i], nums[idx]);
            helper(i + 1, nums);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        helper(0, nums);
        return ans;
    }
};
