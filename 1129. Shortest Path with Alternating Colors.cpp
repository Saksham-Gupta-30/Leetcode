class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int, int>> graph[n];
        vector<int> dist(n, -1);
        dist[0] = 0;
        vector<vector<bool>> visit(n, vector<bool>(2));
        visit[0][1] = visit[0][0] = true;
        for (auto it: redEdges) graph[it[0]].push_back({it[1], 0});
        for (auto it: blueEdges) graph[it[0]].push_back({it[1], 1});
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, -1}});
        while (!q.empty()) {
            int node = q.front().first;
            int dis = q.front().second.first;
            int prevCol = q.front().second.second;
            q.pop();
            for (auto it: graph[node]) {
                int adjNode = it.first;
                int colr = it.second;
                if (!visit[adjNode][colr] && colr != prevCol) {
                    visit[adjNode][colr] = true;
                    q.push({adjNode, {1 + dis, colr}});
                    if (dist[adjNode] == -1) dist[adjNode] = 1 + dis;
                }
            }
        }
        return dist;
    }
};
