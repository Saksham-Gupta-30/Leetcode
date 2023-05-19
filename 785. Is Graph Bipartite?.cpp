class Solution {
public:
    bool isBipartite(int node, vector<vector<int>>& graph, vector<int>& vis, int col) {
        vis[node] = col;
        for (auto it: graph[node]) {
            if (vis[it] == -1) {
                if (isBipartite(it, graph, vis, !col) == false) return false;
            }
            else if (vis[it] == vis[node]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n, -1);
        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                if (isBipartite(i, graph, vis, 0) == false) return false;
            }
        }
        return true;
    }
};
