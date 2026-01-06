class Solution {
public:
    vector<int> ans;

    void helper(int i, vector<int>& arr, int sum) {
        if (i == arr.size()) {
            ans.push_back(sum);
            return;
        }

        helper(i + 1, arr, sum);

        helper(i + 1, arr, sum + arr[i]);
    }

    vector<int> subsetSums(vector<int>& arr) {
        ans.clear();
        helper(0, arr, 0);
        return ans;
    }
};
