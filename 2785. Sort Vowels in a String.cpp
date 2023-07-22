class Solution {
public:
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U')
            return true;
        return false;
    }
    string sortVowels(string s) {
        vector<char> vec;
        for (auto &it: s) {
            if (isVowel(it)) vec.push_back(it);
        }
        sort(vec.begin(), vec.end());
        int i = 0;
        string t = "";
        for (auto &it: s) {
            if (isVowel(it)) {
                t += vec[i];
                i++;
            }
            else t += it;
        }
        return t;
    }
};
