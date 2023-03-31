class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();

            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            
            dq.push_back(i);

            if (i >= k - 1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
    long long solve(int k, vector<int> &chargeTimes, vector<int> &runningCosts, long long budget) {
        vector<int> maxNum = maxSlidingWindow(chargeTimes, k);
        int n = chargeTimes.size();
        long long sum = 0, ans = 0;

        for (int i = 0; i < k; i++) {
            sum += runningCosts[i];
        }
        if (maxNum[0] + k * sum <= budget) {
            ans = maxNum[0] + k * sum;
        }

        for (int i = k; i < n; i++) {
            sum += runningCosts[i];
            sum -= runningCosts[i - k];
            long long cal = maxNum[i - k + 1] + k * sum;
            if (cal <= budget) {
                if (ans < cal) ans = cal;
            }
        }

        return ans;
    }
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = runningCosts.size();
        if (n == 1) {
            if (budget >= chargeTimes[0] + runningCosts[0]) return 1;
            return 0;
        }
        int high = n, low = 1, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int num = solve(mid, chargeTimes, runningCosts, budget);
            if (num <= budget && num != 0) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};
