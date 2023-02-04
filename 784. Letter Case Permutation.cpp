class Solution {
public:
    void bt(string t, string& s, vector<string>& ans, int i) {
        if (i > s.size()) return;
        if (t.size() == s.size()) {
            ans.push_back(t);
            return;
        }
        if (isdigit(s[i])) {
            bt(t + s[i], s, ans, i + 1);
            return;
        }
        bt(t + (char)tolower(s[i]), s, ans, i + 1);
        bt(t + (char)toupper(s[i]), s, ans, i + 1);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string t = "";
        bt(t, s, ans, 0);
        return ans;
    }
};
