class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, cmx = -1;
        for (int i = 0; i < arr.size(); i++) {
            cmx = max(cmx, arr[i]);
            if (cmx == i) ans++;
        }
        return ans;
    }
};
