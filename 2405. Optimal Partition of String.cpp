class Solution {
public:
    int partitionString(string s) {
        unordered_map<char, int> mp;
        int count = 0;
        for (auto it: s) {
            if (mp.find(it) != mp.end()) {
                mp.clear();
                count++;
                mp[it]++;
            }
            else {
                mp[it]++;
            }
        }
        return count + 1;
    }
};
