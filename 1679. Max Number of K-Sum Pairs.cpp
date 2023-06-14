class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[j] + nums[i] > k) j--;
            else if (nums[j] + nums[i] == k) count++, j--, i++;
            else if (nums[j] + nums[i] < k) i++;
        }
        return count;
    }
};
