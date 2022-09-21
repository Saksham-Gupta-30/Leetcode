class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int> ans;
        for (auto it: nums)
            if ((it & 1) == 0)
                sum += it;
        for (auto it: queries) {
            int x = nums[it[1]];
            if ((x & 1) == 0) sum -= x;
            nums[it[1]] += it[0];
            if ((nums[it[1]] & 1) == 0) {
                sum += nums[it[1]];
                ans.emplace_back(sum);
            }
            else ans.emplace_back(sum);
        }
        return ans;
    }
};
