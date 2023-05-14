class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for (auto it: nums) {
            if (it % 2 == 0) pos.push_back(it);
            else neg.push_back(it);
        }
        pos.insert(pos.end(), neg.begin(), neg.end());
        return pos;
    }
};
