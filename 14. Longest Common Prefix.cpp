class Solution {
public:
    string solve(string a, string b) {
        int n = a.size() < b.size() ? a.size() : b.size();
        string s = "";
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) s += a[i];
            else return s;
        }
        return s;
    }
    string longestCommonPrefix(vector<string>& strs) {
        string a = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            a = solve(a, strs[i]);
            if (a == "") return a;
        }
        return a;
    }
};
