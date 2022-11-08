class Solution {
public:
    void helper(int i, vector<string>& ans, string s, unordered_map<char, string>& umap, string digits) {
        if (i == digits.size()) {
            ans.push_back(s);
            return;
        }

        for (int k = 0; k < umap[digits[i]].size(); k++) {
            helper(i + 1, ans, s + umap[digits[i]][k], umap, digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> umap;
        umap['2'] = "abc";
        umap['3'] = "def";
        umap['4'] = "ghi";
        umap['5'] = "jkl";
        umap['6'] = "mno";
        umap['7'] = "pqrs";
        umap['8'] = "tuv";
        umap['9'] = "wxyz";
        vector<string> ans;
        if (digits.size() == 0) return ans;
        string s;
        helper(0, ans, s, umap, digits);
        return ans;
    }
};
