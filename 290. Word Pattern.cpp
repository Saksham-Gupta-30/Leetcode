class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> umap;
        unordered_map<string, char> umap2;
        vector<string> vec;
        string word = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                vec.push_back(word);
                word = "";
            }
            else word += s[i];
        }
        vec.push_back(word);
        if (vec.size() != pattern.size()) return false;
        for (int i = 0; i < pattern.size(); i++) {
            if (umap.find(pattern[i]) == umap.end() && umap2.find(vec[i]) == umap2.end()) {
                umap[pattern[i]] = vec[i];
                umap2[vec[i]] == pattern[i];
            }
            else {
                if (umap[pattern[i]] != vec[i]) return false;
            }
        }
        return true;
    }
};
