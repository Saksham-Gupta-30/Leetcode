class Solution {
public:
    int ultimateParent(int node, vector<int>& parent) {
        if (node == parent[node]) return node;
        return parent[node] = ultimateParent(parent[node], parent);
    }
    void unionBySize(int u, int v, vector<int>& size, vector<int>& parent) {
        int uP = ultimateParent(u, parent);
        int vP = ultimateParent(v, parent);
        
        if (uP == vP) return;
        if (size[uP] < size[vP]) {
            parent[uP] = vP;
            size[vP] += size[uP];
        }
        else {
            parent[vP] = uP;
            size[uP] += size[vP];
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> size(n * n), parent(n * n);
        for (int i = 0; i < n * n; i++) {
            size[i] = 1;
            parent[i] = i;
        }
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                            if (grid[nr][nc] == 1) {
                                int node = i * n + j;
                                int adjNode = nr * n + nc;
                                unionBySize(node, adjNode, size, parent);
                            }
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    set<int> components;
                    for (int k = 0; k < 4; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                            if (grid[nr][nc] == 1) {
                                components.insert(ultimateParent(nr * n + nc, parent));
                            }
                        }
                    }
                    
                    int sizeT = 0;
                    for (auto it: components) {
                        sizeT += size[it];
                    }
                    ans = max(ans, sizeT + 1);
                }
            }
        }
        
        for (int i = 0 ; i < n * n; i++) {
            ans = max(ans, size[ultimateParent(i, parent)]);
        }
        
        return ans;
    }
};
