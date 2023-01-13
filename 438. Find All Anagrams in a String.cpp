class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};
        vector<int> freq(26, 0), window(26, 0), ans;
        for (int i = 0; i < p.size(); i++) {
            freq[p[i] - 'a']++;
            window[s[i] - 'a']++;
        }

        if (freq == window) ans.push_back(0);
        for (int i = p.size(); i < s.size(); i++) {
            window[s[i - p.size()] - 'a']--;
            window[s[i] - 'a']++;

            if (freq == window) ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};
