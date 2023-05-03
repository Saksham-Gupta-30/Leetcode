class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1, n2;
        vector<int> v1, v2;
        for (auto &it: nums1) n1.insert(it);
        for (auto &it: nums2) n2.insert(it);
        for (auto &it: n1) {
            if (!n2.count(it)) v1.push_back(it);
        }
        for (auto &it: n2) {
            if (!n1.count(it)) v2.push_back(it);
        }
        return {v1, v2};
    }
};
