class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mp;
        for (auto it: arr) {
            int dis = abs(it - x);
            mp.push({dis, it});
        }
        vector<int> ans;
        while(k--) {
            ans.emplace_back(mp.top().second);
            mp.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
