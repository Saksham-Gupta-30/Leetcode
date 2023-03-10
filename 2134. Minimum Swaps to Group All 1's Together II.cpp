class Solution {
public:
    int minSwaps(vector<int>& arr) {
        int cnt = 0, n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) cnt++;
        }
        int freq = 0, maxFreq = 0;
        for (int i = 0; i < cnt; i++) {
            if (arr[i] == 1) freq++;
        }
        maxFreq = max(maxFreq, freq);
        for (int i = cnt; i < n; i++) {
            if (arr[i - cnt] == 1) freq--;
            if (arr[i] == 1) freq++;
            maxFreq = max(maxFreq, freq);
        }
        for (int i = 0; i < cnt - 1; i++) {
            if (arr[i] == 1) freq++;
            if (arr[n - cnt + i] == 1) freq--;
            maxFreq = max(maxFreq, freq);
        }
        return cnt - maxFreq;
    }
};
