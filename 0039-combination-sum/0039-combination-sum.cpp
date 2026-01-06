class Solution {
public:
    vector<vector<int>> ans;

    void helper(int i, vector<int>& candidates, int target, vector<int>& arr) {
        if (target == 0) {
            ans.push_back(arr);
            return;
        }

        if (i == candidates.size() || target < 0) {
            return;
        }

        arr.push_back(candidates[i]);
        helper(i, candidates, target - candidates[i], arr);
        arr.pop_back();

        helper(i + 1, candidates, target, arr);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        helper(0, candidates, target, arr);
        return ans;
    }
};
