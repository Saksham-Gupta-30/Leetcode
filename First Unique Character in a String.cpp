class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> mp;
        for (auto it: s) {
            mp[it]++;
        }
        vector<char> vec;
        for (auto it: mp) {
            if (it.second == 1)
                vec.push_back(it.first);
        }
        for (int i = 0; i < s.length(); i++) {
            for (auto it: vec)
                if (it == s[i]) return i;
        }
        return -1;
    }
};
