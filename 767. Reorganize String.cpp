class Solution {
public:
    string reorganizeString(string s) {
        vector<int> alpha(26, 0);
        for (auto &it: s) {
            alpha[it - 'a']++;
        }
        int n = s.size(), maxCount = 0, letter = 0;
        for (int i = 0; i < 26; i++) {
            if (alpha[i] > maxCount) {
                maxCount = alpha[i];
                letter = i;
            }
        }
        string ans = s;
        if (maxCount > (n + 1) / 2) return "";
        int ind = 0;
        while (alpha[letter] != 0) {
            ans[ind] = char(letter + 'a');
            ind += 2;
            alpha[letter]--;
        }
        for (int i = 0; i < 26; i++) {
            while (alpha[i]--) {
                if (ind >= n) {
                    ind = 1;
                }
                ans[ind] = char(i + 'a');
                ind += 2;
            }
        }
        return ans;
    }
};
