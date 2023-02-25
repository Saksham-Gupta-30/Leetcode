class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long long target) {
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            long long a = nums[i];
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                long long b = nums[j];
                int k = j + 1, l = n - 1;
                while (k < l) {
                    long long sum = nums[k] + nums[l];
                    if (sum == target - (a + b)) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++, l--;
                        while (k < nums.size() && nums[k] == nums[k - 1]) k++;
                        while (l > 0 && nums[l] == nums[l + 1]) l--;
                    }
                    else if (sum > target - (a + b)) l--;
                    else k++;
                }
            }
        }
        return ans;
    }
};
