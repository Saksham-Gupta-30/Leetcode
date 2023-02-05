class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int, bool> umap;
        int sum = 0;
        vector<int> ans;
        for (auto it: banned) umap[it] = true;
        for (int i = 1; i <= n; i++) {
            if (umap.find(i) == umap.end() && sum + i <= maxSum) {
                ans.push_back(i);
                sum += i;
            }
        }
        return ans.size();
    }
};
