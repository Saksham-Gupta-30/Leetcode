class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> mp(26, 1e6);
        for (int i = 0; i < chars.size(); i++) mp[chars[i] - 'a'] = vals[i];
        for (int i = 0; i < 26; i++) {
            if (mp[i] == 1e6) mp[i] = i + 1;
        }

        int ans = 0;
        int sum = 0;
        for (auto &it: s) {
            if (sum + mp[it - 'a'] > 0) {
                sum += mp[it - 'a'];
                ans = max(ans, sum);
            }
            else sum = 0;
        }
        return ans;
    }
};
