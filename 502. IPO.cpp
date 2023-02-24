class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> ipo;
        for (int i = 0; i < n; i++) ipo.push_back({capital[i], profits[i]});
        sort(ipo.begin(), ipo.end());
        priority_queue<int> pq;
        int i = 0;
        while (k--) {
            while (i < n && ipo[i].first <= w) pq.push(ipo[i++].second);
            if (pq.empty()) break;
            w += pq.top(), pq.pop();
        }
        return w;
    }
};
