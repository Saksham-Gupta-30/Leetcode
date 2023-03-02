class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int cnt = 0;
        int n = chars.size();
        for (int j = 0; j < n; j++) {
            if (cnt == 0) cnt++;
            else if (chars[j] != chars[j - 1]) {
                if (cnt == 1) {
                    chars[i] = chars[j - 1];
                    i++;
                }
                else {
                    string x = to_string(cnt);
                    chars[i] = chars[j - 1];
                    i++;
                    for (auto &it: x) {
                        chars[i] = it;
                        i++;
                    }
                    cnt = 1;
                }
            }
            else cnt++;
        }
        if (cnt == 1) {
            chars[i] = chars[n - 1];
            i++;
        }
        else {
            string x = to_string(cnt);
            chars[i] = chars[chars.size() - 1];
            i++;
            for (auto &it: x) {
                chars[i] = it;
                i++;
            }
        }
        return i;
    }
};
