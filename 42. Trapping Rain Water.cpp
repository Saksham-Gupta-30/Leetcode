class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefMax(n, 0), sufMax(n, 0);
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            prefMax[i] = maxi;
            maxi = max(maxi, height[i]);
        }
        maxi = 0;
        for (int i = n - 1; i >= 0; i--) {
            sufMax[i] = maxi;
            maxi = max(maxi, height[i]);
        }
        int water = 0;
        for (int i = 1; i < n - 1; i++) {
            int w = min(prefMax[i], sufMax[i]) - height[i];
            if (w > 0) water += w;
        }
        return water;
    }
};
