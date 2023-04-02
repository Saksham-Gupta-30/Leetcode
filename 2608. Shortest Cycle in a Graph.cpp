class Solution {
public:
    int solve(vector<int> gr[], int i, int n) {
        vector<int> dist(n, 0);
        queue<vector<int>> q;
        q.push({i, 0, -1});
        int lvl = 0;
        while (!q.empty()) {
            auto temp = q.front();
            int lvl = temp[1];
            int node = temp[0];
            int parent = temp[2];
            q.pop();

            for (auto &it: gr[node]) {
                if (it == parent) continue;
                if (dist[it]) return dist[it] + lvl;
                else {
                    dist[node] = lvl + 1;
                    q.push({it, lvl + 1, node});
                }
            }
        }
        return lvl + 1;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int> gr[n];
        int ans = INT_MAX;
        vector<int> indegree(n, 0), vis(n, 0);
        for (auto &edge: edges) {
            indegree[edge[0]]++;
            indegree[edge[1]]++;
            gr[edge[0]].push_back(edge[1]);
            gr[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) vis[i] = 1;
            if (indegree[i] == 1) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            vis[node] = 1;

            indegree[node]--;
            for (auto &it: gr[node]) {
                indegree[it]--;
                if (indegree[it] == 1) q.push(it);
            }
        }

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                int cycleLength = solve(gr, i, n);
                ans = min(ans, cycleLength);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
