class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;
        vector<int> vis(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        while (!pq.empty()) {
            int ind = pq.top().second;
            int num = pq.top().first;
            pq.pop();
            
            if (vis[ind] == 0) {
                score += nums[ind];
                vis[ind] = 1;
                if (ind - 1 >= 0) vis[ind - 1] = 1;
                if (ind + 1 < n) vis[ind + 1] = 1;
            }
        }
        return score;
    }
};
