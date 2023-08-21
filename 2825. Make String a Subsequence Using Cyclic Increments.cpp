class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if (str2.size() > str1.size()) return false;
        int j = 0;
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] == str2[j]) j++;
            else {
                if (str1[i] == 'z' && str2[j] == 'a') j++;
                else if (char(str1[i] + 1) == str2[j]) j++;
                else continue;
            }
            
            if (j == str2.size()) return true;
        }
        return false;
    }
};
