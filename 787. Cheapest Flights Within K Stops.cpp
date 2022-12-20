class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        vector<pair<int,int>> adj[n];
        for (auto it: flights) adj[it[0]].push_back({it[1], it[2]});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if (stops > k) continue;

            for (auto iter: adj[node]) {
                int adjNode = iter.first;
                int cst = iter.second;
                if (cst + cost < dist[adjNode] && stops <= k) {
                    dist[adjNode] = cost + cst;
                    q.push({stops + 1, {adjNode, cost + cst}});
                }
            }
        }

        if (dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};
