class Solution {
public:
    void dfs(int node, vector<vector<int>>& ans, vector<int>& vec, vector<vector<int>>& graph, int n) {
        vec.push_back(node);
        if (node == n - 1) {
            ans.push_back(vec);
            return;
        }
        
        for (auto it: graph[node]) {
            dfs(it, ans, vec, graph, n);
            vec.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> vec;
        dfs(0, ans, vec, graph, n);
        return ans;
    }
};
