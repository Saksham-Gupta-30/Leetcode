class Solution {
public:
    bool operator()(const pair<int, int> &left, const pair<int, int> &right) {
        return left.second < right.second;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> pairs;
        int n = nums1.size();
        for (int i = 0; i < n; i++) pairs.push_back({nums1[i], nums2[i]});
        sort(pairs.rbegin(), pairs.rend(), Solution());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long kSum = 0;
        for (int i = 0; i < k; i++) {
            kSum += pairs[i].first;
            pq.push(pairs[i].first);
        }
        long long ans = kSum * pairs[k - 1].second;
        for (int i = k; i < n; i++) {
            kSum += pairs[i].first - pq.top();
            pq.pop();
            pq.push(pairs[i].first);
            ans = max(ans, kSum * pairs[i].second);
        }
        return ans;
    }
};
