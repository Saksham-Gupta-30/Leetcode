class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n, 0), curr(n, 0);
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) dp[i] = matrix[n - 1][i];

        for (int i = n - 2; i >= 0; i--) {
            int downLeft = 1e9, downRight = 1e9;
            for (int j = 0; j < n; j++) {
                int down = matrix[i][j] + dp[j];
                if (j - 1 >= 0) downLeft = matrix[i][j] + dp[j - 1];
                if (j + 1 < n) downRight = matrix[i][j] + dp[j + 1];
                curr[j] = min(down, min(downLeft, downRight));
            }
            dp = curr;
        }
        for (int i = 0; i < n; i++) mini = min(mini, dp[i]);
        return mini;
    }
};
