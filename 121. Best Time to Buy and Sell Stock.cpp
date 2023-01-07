class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MIN = prices[0], profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            MIN = min(prices[i], MIN);
            profit = max(profit, prices[i] - MIN);
        }
        return profit;
    }
};
