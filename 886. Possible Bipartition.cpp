class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> graph[n + 1];
        for (auto it: dislikes) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        queue<int> q;
        vector<int> vis(n + 1, -1);

        for (int i = 1; i < n + 1; i++) {
            if (vis[i] == -1) {
                vis[i] = 0;
                q.push(i);
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto it: graph[node]) {
                        if (vis[it] == -1) {
                            vis[it] = abs(vis[node] - 1);
                            q.push(it);
                        }
                        else if (vis[it] == vis[node]) return false;
                    }
                }
            }
        }
        return true;
    }
};
