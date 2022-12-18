class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long, long>> adj[n];
        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
        vector<long> dist(n, LONG_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        for (auto it: roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        pq.push({0, 0});
        long mod = 1000000007;
        
        while (!pq.empty()) {
            long dis = pq.top().first;
            long node = pq.top().second;
            pq.pop();

            for (auto it: adj[node]) {
                long adjNode = it.first;
                long wt = it.second;

                if (dis + wt < dist[adjNode]) {
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node] % mod;
                }
                else if (dis + wt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};
