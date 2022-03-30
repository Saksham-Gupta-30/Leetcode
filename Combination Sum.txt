class Solution {
public:
    void recursion(int ind, vector<int> &ds, int target, vector<int> &arr, vector<vector<int>> &ans) {
        if (ind == arr.size()) {
            if (target == 0) ans.push_back(ds);
            return;
        }
        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            recursion(ind, ds, target - arr[ind], arr, ans);
            ds.pop_back();
        }
        recursion(ind + 1, ds, target, arr, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        recursion(0, ds, target, candidates, ans);
        return ans;
    }
};
