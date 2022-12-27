class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> vec;
        for (int i = 0; i < rocks.size(); i++) {
            vec.push_back(capacity[i] - rocks[i]);
        }
        sort(vec.begin(), vec.end());

        int ans = 0;
        for (auto it: vec) {
            if (it == 0) ans++;
            else if (additionalRocks >= it) {
                ans++;
                additionalRocks -= it;
            }
        }

        return ans;
    }
};
