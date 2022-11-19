class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (auto it: words) {
            unordered_map<char, char> mp0;
            unordered_map<char, char> mp1;
            bool flag = true;
            for (int i = 0; i < pattern.size(); i++) {
                if (mp0.find(it[i]) == mp0.end()) {
                    if (mp1.find(pattern[i]) == mp1.end()) {
                        mp0[it[i]] = pattern[i];
                        mp1[pattern[i]] = it[i];
                    }
                    else {
                        flag = false;
                        break;
                    }
                }
                else {
                    if (mp0[it[i]] == pattern[i] && mp1[pattern[i]] == it[i]) continue;
                    else {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag == true) ans.push_back(it);
        }
        return ans;
    }
};
