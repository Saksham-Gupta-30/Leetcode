class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            if (k % 2 == 1) return -1;
            return nums[0];
        }
        if (k == 0) return nums[0];
        priority_queue<int> pq;
        int ans = INT_MIN;
        if (k < nums.size()) {
            for (int i = 0; i < k; i++) pq.push(nums[i]);
            if (nums[k] > pq.top()) ans = nums[k];
            else if (nums[k - 1] == pq.top()) {
                pq.pop();
                if (!pq.empty()) {
                    if (pq.top() > nums[k]) ans = pq.top();
                    else ans = nums[k];
                }
                else ans = nums[k];
            }
            else ans = pq.top();
        }
        else if (nums.size() == k) {
            for (int i = 0; i < k; i++) pq.push(nums[i]);
            if (pq.top() == nums[k - 1]) {
                pq.pop();
                ans = pq.top();
            }
            else ans = pq.top();
        }
        else for (int i = 0; i < nums.size(); i++) ans = max(ans, nums[i]);
        return ans;
    }
};
