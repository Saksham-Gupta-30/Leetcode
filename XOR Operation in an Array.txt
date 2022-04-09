class Solution {
public:
    int xorOperation(int n, int start) {
        int temp = start;
        for (int i = 1; i < n; i++) {
            start = start ^ (temp + 2 * i);
        }
        return start;
    }
};
