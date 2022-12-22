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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n), size(n);
        for (int i = 0; i < n ; i++) {
            parent[i] = i;
            size[i] = 1;
        }

        unordered_map<string, int> mapMailNode;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mapMailNode.find(mail) == mapMailNode.end()) mapMailNode[mail] = i;
                else unionBySize(i, mapMailNode[mail], size, parent);
            }
        }

        vector<string> mergeMail[n];
        for (auto it: mapMailNode) {
            string mail = it.first;
            int node = findUltimateParent(it.second, parent);
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            if (mergeMail[i].size() == 0) continue;
            sort(mergeMail[i].begin(), mergeMail[i].end());
            vector<string> vec;
            vec.push_back(accounts[i][0]);
            for (auto it: mergeMail[i]) vec.push_back(it);
            ans.push_back(vec);
        }

        return ans;
    }
};
