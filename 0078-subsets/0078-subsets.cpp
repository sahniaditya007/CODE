class Solution {
public:
    vector<vector<int>> ans;

    void subsetsHelper(int i, vector<int>& nums, vector<int>& arr) {
        if (i == nums.size()) {
            ans.push_back(arr);
            return;
        }

        arr.push_back(nums[i]);
        subsetsHelper(i + 1, nums, arr);

        arr.pop_back();
        subsetsHelper(i + 1, nums, arr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        subsetsHelper(0, nums, arr);
        return ans;
    }
};