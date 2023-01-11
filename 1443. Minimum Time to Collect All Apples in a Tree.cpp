class Solution {
public:
    void dfs(int node, vector<int> tree[], vector<bool>& hasApple, vector<int>& vis, vector<int>& time) {
        vis[node] = 1;
        for (auto it: tree[node]) {
            if (vis[it] == 0) {
                time[node] += 1;
                dfs(it, tree, hasApple, vis, time);
                if (hasApple[it] == true) {
                    time[node] += time[it] + 1;
                } else {
                    if (time[it] > 0) time[node] += time[it] + 1;
                    else time[node] -= 1;
                }
            }
        }
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> tree[n];
        for (auto it: edges) {
            tree[it[0]].push_back(it[1]);
            tree[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0), time(n, 0);
        dfs(0, tree, hasApple, vis, time);
        return time[0];
    }
};
