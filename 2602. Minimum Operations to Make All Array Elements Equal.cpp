class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        long long n = nums.size(), m = queries.size(), j = 0;
        vector<long long> ans(m, 0), prefixSum(n), suffixSum(n);
        prefixSum[0] = nums[0];
        suffixSum[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) prefixSum[i] = prefixSum[i - 1] + nums[i];
        for (int i = n - 2; i >= 0; i--) suffixSum[i] = suffixSum[i + 1] + nums[i];
        for (auto &it: queries) {
            long long count = 0;;
            long long lb = lower_bound(nums.begin(), nums.end(), it) - nums.begin();
            long long ub = upper_bound(nums.begin(), nums.end(), it) - nums.begin();
            
            if (lb == 0) {
                if (nums[0] == it) {
                    if (ub != n) count += (suffixSum[ub] - (n - ub) * it);
                }
                else count += (suffixSum[0] - n * it);
            }
            else if (lb == n) count += (n * it - prefixSum[n - 1]);
            else if (lb == n - 1) {
                if (nums[lb] == it) count += (lb * it - prefixSum[lb - 1]);
                else {
                    count += (lb * it - prefixSum[lb - 1]);
                    count += nums[lb] - it;
                }
            }
            else {
                if (nums[lb] == it) {
                    count += (lb * it - prefixSum[lb - 1]);
                    if (ub != n) count += (suffixSum[ub] - (n - ub) * it);
                }
                else {
                    count += (lb * it - prefixSum[lb - 1]);
                    count += (suffixSum[ub] - (n - ub) * it);
                }
            }

            ans[j] = count;
            j++;
        }
        return ans;
    }
};
