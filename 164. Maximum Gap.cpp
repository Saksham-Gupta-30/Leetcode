class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int minNum = INT_MAX, maxNum = INT_MIN;
        for (int i = 0; i < n; i++) {
            minNum = min(minNum, nums[i]);
            maxNum = max(maxNum, nums[i]);
        }
        if (minNum == maxNum) return 0;
        int gap = (maxNum - minNum) / (n - 1);
        if ((maxNum - minNum) % (n - 1) != 0) gap++;
        vector<int> minArr(n, INT_MAX), maxArr(n, INT_MIN);
        for (int i = 0; i < n; i++) {
            int bkt = (nums[i] - minNum) / gap;
            minArr[bkt] = min(minArr[bkt], nums[i]);
            maxArr[bkt] = max(maxArr[bkt], nums[i]);
        }
        int ans = INT_MIN;
        int prev = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (minArr[i] == INT_MAX) continue;
            if (prev == INT_MIN) prev = maxArr[i];
            else {
                ans = max(ans, minArr[i] - prev);
                prev = maxArr[i];
            }
        }
        return ans;
    }
};
