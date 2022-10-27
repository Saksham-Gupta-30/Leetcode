class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 2) return max(nums[0], nums[1]);
        if (nums.size() == 1) return nums[0];
        int prev = nums[0];
        int prev2 = 0;
        for (int i = 1; i < nums.size() - 1; i++) {
            int pick = nums[i];
            if (i > 1) pick += prev2;
            int notPick = prev;
            int curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        
        int last = nums[1];
        int slast = 0;
        for (int i = 2; i < nums.size(); i++) {
            int pick = nums[i];
            if (i > 2) pick += slast;
            int notPick = last;
            int curr = max(pick, notPick);
            slast = last;
            last = curr;
        }
        return max(prev, last);
    }
};
