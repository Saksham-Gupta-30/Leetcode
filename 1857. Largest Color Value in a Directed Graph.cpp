class Solution {
public:
    int ans = 1;
    int solve(vector<int> adj[], vector<int> &vis, vector<int> &pathVis, int node, string &colors, vector<vector<int>> &mp) {
        if (pathVis[node]) return INT_MAX;
        if (vis[node]) return mp[node][colors[node] - 'a'];
        pathVis[node] = 1;
        vis[node] = 1;

        for (auto &adjNode: adj[node]) {
            if (solve(adj, vis, pathVis, adjNode, colors, mp) == INT_MAX) return INT_MAX;
            for (int i = 0; i < 26; i++) {
                mp[node][i] = max(mp[node][i], mp[adjNode][i]);
            }
        }
        pathVis[node] = 0;
        mp[node][colors[node] - 'a']++;
        return mp[node][colors[node] - 'a'];
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> adj[n];

        for (auto &edge: edges) adj[edge[0]].push_back(edge[1]);

        vector<int> vis(n, 0), pathVis(n, 0);
        vector<vector<int>> mp(n, vector<int> (26));

        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(adj, vis, pathVis, i, colors, mp));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
