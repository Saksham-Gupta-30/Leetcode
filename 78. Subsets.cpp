class Solution {
public:
    void subset(vector<vector<int>> &ans, int i, vector<int> &ds, vector<int> &nums) {
        if (i == nums.size()) {
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        subset(ans, i + 1, ds, nums);
        ds.pop_back();
        subset(ans, i + 1, ds, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        subset(ans, 0, ds, nums);
        return ans;
    }
};
