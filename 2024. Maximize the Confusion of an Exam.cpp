class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int j = 0;
        int len = 0, ans = 0;
        int l = k;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'T') {
                len++;
                ans = max(ans, len);
            }
            else {
                if (k == 0) {
                    if (s[j] == 'T') {
                        while (s[j] != 'F') {
                            j++;
                            len--;
                        }
                        j++;
                    }
                    else {
                        j++;
                    }
                }
                else {
                    k--;
                    len++;
                    ans = max(ans, len);
                }
            }
        }
        len = 0, j = 0, k = l;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'F') {
                len++;
                ans = max(ans, len);
            }
            else {
                if (k == 0) {
                    if (s[j] == 'F') {
                        while (s[j] != 'T') {
                            j++;
                            len--;
                        }
                        j++;
                    }
                    else {
                        j++;
                    }
                }
                else {
                    k--;
                    len++;
                    ans = max(ans, len);
                }
            }
        }
        return ans;
    }
};
