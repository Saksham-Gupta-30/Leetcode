class Solution {
public:
    string reverseWords(string s) {
        int j;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (count == 0) j = i;
                count++;
            }
            else {
                if (count != 0) {
                    reverse(s.begin() + j, s.begin() + j + count);
                    count = 0;
                }
            }
        }
        if (count != 0) reverse(s.begin() + j, s.begin() + j + count);
        return s;
    }
};
