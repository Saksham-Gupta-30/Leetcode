class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, count = 1;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[j - 1]) {
                i++;
                nums[i] = nums[j];
                count = 1;
            }
            else {
                if (nums[i + 1] != nums[j] && count == 1) {
                    nums[i + 1] = nums[j];
                    i++, count++;
                } 
                if (count < 2) {
                    count++, i++;
                }
            }
        }
        return i + 1;
    }
};
