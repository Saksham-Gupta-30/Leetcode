class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        for (auto& it: roads) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int cnt = 0;
                for (auto& it: adj[i]) {
                    cnt++;
                }
                for (auto& it: adj[j]) {
                    if (it != i) cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
