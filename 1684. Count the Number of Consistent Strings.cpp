class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> mp;
        bool flag;
        int count = 0;
        for (auto it: allowed) mp[it] = 1;
        for (auto it: words) {
            flag = true;
            for (auto i: it) {
                if (mp.find(i) == mp.end()) flag = false;
            }
            if (flag == true) count++;
        }
        return count;
    }
};
