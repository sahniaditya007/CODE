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

        for (int idx = i; idx < candidates.size(); idx++) {
            if (idx > i && candidates[idx] == candidates[idx - 1]) continue;
            if (candidates[idx] > target) break;

            arr.push_back(candidates[idx]);
            helper(idx + 1, candidates, target - candidates[idx], arr);
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> arr;
        helper(0, candidates, target, arr);
        return ans;
    }
};
