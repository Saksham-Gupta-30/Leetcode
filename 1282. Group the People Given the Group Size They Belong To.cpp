class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < groupSizes.size(); i++) {
            if (mp.find(groupSizes[i]) != mp.end()) {
                if (mp[groupSizes[i]].size() < groupSizes[i]) mp[groupSizes[i]].push_back(i);
                if (mp[groupSizes[i]].size() == groupSizes[i]) {
                    ans.push_back(mp[groupSizes[i]]);
                    mp[groupSizes[i]].clear();
                    // mp[groupSizes[i]].push_back(i);
                }
            }
            else {
                mp[groupSizes[i]].push_back(i);
                if (mp[groupSizes[i]].size() == groupSizes[i]) {
                    ans.push_back(mp[groupSizes[i]]);
                    mp[groupSizes[i]].clear();
                }
            }
        }
        return ans;
    }
};
