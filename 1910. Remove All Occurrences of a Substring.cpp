class Solution {
public:
    string removeOccurrences(string s, string part) {
        int size = s.size();
        while (size == s.size()) {
            string x = "";
            bool flag = true;
            for (int i = 0; i < s.size() && flag == true; i++) {
                if (s[i] == part[0]) {
                    if (s.substr(i, part.size()) == part) {
                        x += s.substr(i + part.size(), s.size() - i + part.size());
                        flag = false;
                        continue;
                    }
                    else x += s[i];
                }
                else x += s[i];
            }
            s = x;
            if (size == s.size()) break;
            size = s.size();
        }
        return s;
    }
};
