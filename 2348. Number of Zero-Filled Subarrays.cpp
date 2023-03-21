class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                long long count = 0;
                while (i < nums.size() && nums[i] == 0) count++, i++;
                ans += (count * (count + 1) / 2);
                i--;
            }
        }
        return ans;
    }
};
