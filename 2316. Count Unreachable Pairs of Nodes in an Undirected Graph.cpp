class Solution {
public:
    int ultimateParent(vector<long long> &parent, int node) {
        if (node == parent[node]) return node;
        return parent[node] = ultimateParent(parent, parent[node]);
    }
    void unionBySize(vector<long long> &parent, vector<long long> &size, int u, int v) {
        int uparent = ultimateParent(parent, u);
        int vparent = ultimateParent(parent, v);
        if (uparent == vparent) return;

        if (size[uparent] < size[vparent]) {
            parent[uparent] = vparent;
            size[vparent] += size[uparent];
        }
        else {
            parent[vparent] = uparent;
            size[uparent] += size[vparent];
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<long long> size(n, 1), parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        for (auto &it: edges) {
            unionBySize(parent, size, it[0], it[1]);
        }

        long long ans = 0;
        int m = n;
        for (int i = 0; i < n; i++) {
            if (i == parent[i] && m > 0) {
                ans += (size[i] * (m - size[i]));
                m -= size[i];
            }
        }

        return ans;
    }
};
