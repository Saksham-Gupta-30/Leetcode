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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for (auto it: stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        vector<int> size(maxRow + maxCol + 2), parent(maxCol + maxRow + 2);
        for (int i = 0; i <= (maxRow + maxCol + 1); i++) {
            size[i] = 1;
            parent[i] = i;
        }
        unordered_map<int, int> stoneNodes;
        for (auto it: stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            unionBySize(nodeRow, nodeCol, size, parent);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        int count = 0;
        for (auto it: stoneNodes) {
            if (ultimateParent(it.first, parent) == it.first) count++;
        }

        return stones.size() - count;
    }
};
