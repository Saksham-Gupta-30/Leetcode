class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int num = nums[0];
        int ind = upper_bound(nums.begin(), nums.end(), num) - nums.begin();
        int i = 0;
        int cnt = 0;
        while (ind != nums.size()) {
            if (nums[ind] > nums[i]) cnt++, i++, ind++;
            else ind++;
        }
        return cnt;
    }
};
