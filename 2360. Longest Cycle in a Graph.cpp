class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), i = 0;
        vector<int> adj[n], indegree(n, 0), vis(n, 0);
        for (auto &it: edges) {
            if (it == -1) continue;
            indegree[it]++;
        }

        queue<int> q;
        for (int j = 0; j < n; j++) {
            if (indegree[j] == 0) q.push(j);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            vis[node] = 1;

            if (edges[node] != -1) {
                indegree[edges[node]]--;
                if (indegree[edges[node]] == 0) q.push(edges[node]);
            }
        }
        int ans = -1, count = 0;
        for (int j = 0; j < n; j++) {
            if (vis[j] == 0) {
                q.push(j);
                count = 0;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    count++;
                    vis[node] = 1;
                    if (vis[edges[node]] == 0) q.push(edges[node]);
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};
