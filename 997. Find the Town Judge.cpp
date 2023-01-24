class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<bool> vis(n + 1, false);
        vector<int> indegree(n + 1, 0);
        for (auto it: trust) vis[it[0]] = true, indegree[it[1]]++;
        for (int i = 1; i <= n; i++) {
            if (vis[i] == false && indegree[i] == n - 1) return i;
        }
        return -1;
    }
};
