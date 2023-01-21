class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k == 0) {
            if (nums1 == nums2) return 0;
            return -1;
        }
        int n = nums1.size();
        long long sub = 0, add = 0;
        for (int i = 0; i < n; i++) {
            int a = nums1[i], b = nums2[i];
            if (a == b) continue;
            else {
                if (a < b && (b - a) % k == 0) {
                    sub = sub + (b - a) / k;
                }
                else if (a > b && (a - b) % k == 0) {
                    add = add + (a - b) / k;
                }
                else return -1;
            }
        }
        if (sub == add) return add;
        return -1;
    }
};
