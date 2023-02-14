class Solution {
public:
    long long bfs(int n, int seats, vector<int>& degree, vector<int> graph[]) {
        queue<int> q;
        long long fuels = 0;
        for (int i = 1; i < n; i++) {
            if (degree[i] == 1)
                q.push(i);
        }

        vector<int> representative(n, 1);
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            fuels += ceil((double)representative[node] / seats);
            for (auto it: graph[node]) {
                representative[it] += representative[node];
                degree[it]--;
                if (degree[it] == 1 && it != 0)
                    q.push(it);
            }
        }

        return fuels;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<int> graph[n];
        vector<int> degree(n, 0);
        for (auto it: roads) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
            degree[it[0]]++;
            degree[it[1]]++;
        }

        return bfs(n, seats, degree, graph);
    }
};
