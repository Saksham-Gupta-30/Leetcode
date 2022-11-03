class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            if (nums[j] == val) {
                j--;
                continue;
            }
            if (nums[i] == val) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            else i++;
        }
        return j + 1;
    }
};
