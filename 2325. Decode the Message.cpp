class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, char> mp;
        mp['a'] = '0';
        mp['b'] = '0';
        mp['c'] = '0';
        mp['d'] = '0';
        mp['e'] = '0';
        mp['f'] = '0';
        mp['g'] = '0';
        mp['h'] = '0';
        mp['i'] = '0';
        mp['j'] = '0';
        mp['k'] = '0';
        mp['l'] = '0';
        mp['m'] = '0';
        mp['n'] = '0';
        mp['o'] = '0';
        mp['p'] = '0';
        mp['q'] = '0';
        mp['r'] = '0';
        mp['s'] = '0';
        mp['t'] = '0';
        mp['u'] = '0';
        mp['v'] = '0';
        mp['w'] = '0';
        mp['x'] = '0';
        mp['y'] = '0';
        mp['z'] = '0';
        int i = 0;
        for (auto it: key) {
            if (mp[it] == '0') mp[it] = i++ + 'a';
        }
        string s = "";
        for (auto it: message) {
            if (it == ' ') s += ' ';
            else s += mp[it];
        }
        return s;
    }
};
