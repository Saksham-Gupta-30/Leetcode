class Solution {
public:
    int maxProfit(vector<int>& prices) {
        long long t0_st0 = 0, t0_st1 = -prices[0], t1_st0 = INT_MIN, t1_st1 = INT_MIN, t2_st0 = INT_MIN;
        for (int i = 1; i < prices.size(); i++) {
            long long nt0_st0, nt0_st1, nt1_st0, nt1_st1, nt2_st0;
            nt0_st0 = t0_st0;
            nt0_st1 = max(t0_st0 - prices[i], t0_st1);
            nt1_st0 = max(t0_st1 + prices[i], t1_st0);
            nt1_st1 = max(t1_st1, t1_st0 - prices[i]);
            nt2_st0 = max(t2_st0, t1_st1 + prices[i]);
            t0_st0 = nt0_st0, t0_st1 = nt0_st1, t1_st0 = nt1_st0, t1_st1 = nt1_st1, t2_st0 = nt2_st0;
        }
        return max(t0_st0,max(t1_st0,t2_st0));
    }
};
