class Solution {
public:
    void getAllCombinations(vector<int>& arr, int idx, int target,
                            vector<vector<int>>& ans, vector<int>& combin) {

        if (target == 0) {
            ans.push_back(combin);
            return;
        }

        if (idx == arr.size() || target < 0) {
            return;
        }

        combin.push_back(arr[idx]);
        getAllCombinations(arr, idx, target - arr[idx], ans, combin);
        combin.pop_back();

        getAllCombinations(arr, idx + 1, target, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        getAllCombinations(arr, 0, target, ans, combin);
        return ans;
    }
};
