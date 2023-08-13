class Solution {
public:
    unordered_map<int, bool> mp;
    bool isValid(vector<int>& nums, int i) {
        if (mp.find(i) != mp.end()) return mp[i];
        bool ans = false;

        if (i > 0 && nums[i] == nums[i - 1]) ans |= isValid(nums, i - 2);
        if (i > 1 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) ans |= isValid(nums, i - 3);
        if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1) ans |= isValid(nums, i - 3);

        mp[i] = ans;
        return ans;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        mp[-1] = true;

        return isValid(nums, n - 1);
    }
};
