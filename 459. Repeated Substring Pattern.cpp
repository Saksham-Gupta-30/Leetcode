class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 1; i<=s.size()/2; i++)
            if(!(s.size()%i) && s.substr(i) == s.substr(0,s.size()-i)) return true;
        return false;
    }
};
