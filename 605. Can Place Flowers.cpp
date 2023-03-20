class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        if (flowerbed.size() == 1) {
            if (n == 1 && flowerbed.front() == 0) return true;
            return false;
        }
        int m = flowerbed.size();
        for (int i = 0; i < flowerbed.size() - 1; i++) {
            if (i == 0 && flowerbed[i] == 0) {
                if (flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            else if (i != 0 && flowerbed[i] == 0) {
                if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }
        if (flowerbed[m - 1] == 0 && flowerbed[m - 2] == 0) {
            n--;
        }
        if (n <= 0) return true;
        return false;
    }
};
