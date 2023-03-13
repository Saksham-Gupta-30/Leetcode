class Solution {
public:
    int arrangeCoins(int n) {
        long l = 0, h = n;
        while (l <= h) {
            long m = l + (h - l) / 2;
            long S = m * (m + 1) / 2;
            if (S == n) return (int)m;
            if (S > n) h = m - 1;
            else l = m + 1;
        }
        return (int)h;
    }
};
