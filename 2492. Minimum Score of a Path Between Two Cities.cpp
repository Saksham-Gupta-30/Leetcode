class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n + 1];
        for (auto &it: roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int> vis(n + 1, 0);
        queue<int> q;
        q.push(1);
        int ans = INT_MAX;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto &i: adj[node]) {
                if (!vis[i.first] || i.second < ans) {
                    ans = min(ans, i.second);
                    vis[i.first] = 1;
                    q.push(i.first);
                }
            }
        }
        return ans;
    }
};
