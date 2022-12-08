class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<int> g[]) {
        vis[node] = 1;
        for (auto it: g[node]) {
            if (!vis[it]) dfs(it, vis, g);
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> g[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j] == 1 && i != j) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, vis, g);
            }
        }
        return count;
    }
};
