class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0) return true;
        int n = arr.size();
        queue<int> q;
        q.push(start);
        vector<int> vis(n, 0);
        vis[start] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            vis[node] = 1;
            if (arr[node] == 0) return true;
            if (node + arr[node] < n && !vis[node + arr[node]]) q.push(node + arr[node]);
            if (node - arr[node] >= 0 && !vis[node - arr[node]]) q.push(node - arr[node]);
        }
        return false;
    }
};
