class Solution {
public:
    void bt(int ind, set<vector<int>>& ans, vector<int>& nums, vector<int>& ds) {
        if (ds.size() > 1) ans.insert(ds);
        for (int i = ind; i < nums.size(); i++) {
            if (ds.size() == 0 || ds.back() <= nums[i]) {
                ds.push_back(nums[i]);
                bt(i + 1, ans, nums, ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> ds;
        bt(0, ans, nums, ds);
        vector<vector<int>> res;
        for (auto it: ans) res.push_back(it);
        return res;
    }
};
