class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) return {};
        unordered_map<string, int> mp;
        for (int i = 0; i <= s.size() - 10; i++) {
            string window = s.substr(i, 10);
            mp[window]++;
        }
        vector<string> ans;
        for (auto &it: mp) {
            if (it.second > 1) ans.push_back(it.first);
        }
        return ans;
    }
};
