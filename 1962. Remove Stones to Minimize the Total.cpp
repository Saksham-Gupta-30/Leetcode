class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int n = piles.size();
        for (auto it: piles) pq.push(it);
        while (k--) {
            int pile = pq.top();
            pq.pop();
            if (pile % 2 == 1) pile = pile / 2 + 1;
            else pile = pile / 2;
            pq.push(pile);
        }
        int ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
