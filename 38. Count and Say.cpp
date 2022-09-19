class Solution {
public:
    string helper(string s) {
        map<int, string> mp;
        mp[0] = "0";
        mp[1] = "1";
        mp[2] = "2";
        mp[3] = "3";
        mp[4] = "4";
        mp[5] = "5";
        mp[6] = "6";
        mp[7] = "7";
        mp[8] = "8";
        mp[9] = "9";
        string x = "";
        int count = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) count++;
            else {
                x += mp[count];
                x += s[i - 1];
                count = 1;
            }
        }
        x += mp[count];
        x += s[s.size() - 1];
        return x;
    }
    
    string countAndSay(int n) {
        string s = "1";
        while (n != 1) {
            s = helper(s);
            n--;
        }
        return s;
    }
};
