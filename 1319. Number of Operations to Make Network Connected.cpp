class Solution {
public:
    int findUltimateParent(int node, vector<int>& parent) {
        if (node == parent[node]) return node;
        return parent[node] = findUltimateParent(parent[node], parent);
    }
    void unionBySize(int u, int v, vector<int>& size, vector<int>& parent) {
        int uParent = findUltimateParent(u, parent);
        int vParent = findUltimateParent(v, parent);

        if (uParent == vParent) return;
        if (size[uParent] < size[vParent]) {
            parent[uParent] = vParent;
            size[vParent] += size[uParent];
        }
        else {
            parent[vParent] = uParent;
            size[uParent] += size[vParent];
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n > connections.size() && connections.size() != n - 1) return -1;
        vector<int> size(n), parent(n);
        for (int i = 0; i < n; i++) {
            size[i] = 1;
            parent[i] = i;
        }

        for (auto it: connections) {
            unionBySize(it[0], it[1], size, parent);
        }

        int component = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) component++;
        }

        return component - 1;
    }
};
