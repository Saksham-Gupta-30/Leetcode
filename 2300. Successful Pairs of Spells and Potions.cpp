class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            long long num = ceil((double)success / spells[i]);
            int ind = lower_bound(potions.begin(), potions.end(), num) - potions.begin();
            int a = m - ind;
            ans[i] = a;
        }
        return ans;
    }
};
