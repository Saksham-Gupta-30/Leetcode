class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int, int>> adj[n];
        for (auto &it: connections) {
            adj[it[0]].push_back({it[1], 1});
            adj[it[1]].push_back({it[0], 0});
        }
        
        queue<pair<int, int>> q;
        int count = 0;
        q.push({0, -1});
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto &[child, i]: adj[node]) {
                if (child != parent) {
                    count += i;
                    q.push({child, node});
                }
            }
        }
        return count;
    }
};
