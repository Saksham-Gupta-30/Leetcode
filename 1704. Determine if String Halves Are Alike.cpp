class Solution {
public:
    int countVowels(string s) {
        int count = 0;
        for (auto it: s) {
            if (it == 'a' or it == 'A' or it == 'e' or it == 'E' or it == 'i' or it == 'I' or it == 'o' or it == 'O' or it == 'u' or it == 'U') count++;
        }
        return count;
    }
    bool halvesAreAlike(string s) {
        int x = countVowels(s.substr(0, s.size() / 2));
        int y = countVowels(s.substr(s.size() / 2, s.size()));
        if (x == y) return true;
        return false;
    }
};
