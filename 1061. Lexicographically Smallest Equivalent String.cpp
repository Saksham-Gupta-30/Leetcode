class Solution {
public:
    char findUltimateParent(char node, map<char, char>& parent) {
        if (node == parent[node]) return node;
        return parent[node] = findUltimateParent(parent[node], parent);
    }
    void unionBySize(char u, char v, vector<int>& size, map<char, char>& parent) {
        char uParent = findUltimateParent(u, parent);
        char vParent = findUltimateParent(v, parent);

        if (uParent == vParent) return;
        if (size[uParent - 'a'] < size[vParent - 'a']) {
            parent[uParent] = vParent;
        }
        else {
            parent[vParent] = uParent;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        map<char, char> parent;
        vector<int> size(26);
        for (int i = 0; i < 26; i++) {
            parent[char('a' + i)] = char(i + 'a');
            size[i] = 26 - i;
        }

        for (int i = 0; i < s1.size(); i++) {
            if (parent[s1[i]] != parent[s2[i]]) {
                unionBySize(s1[i], s2[i], size, parent);
            }
        }

        string ans = "";
        for (int i = 0; i < baseStr.size(); i++) {
            char s = findUltimateParent(baseStr[i], parent);
            ans += s;
        }

        return ans;
    }
};
