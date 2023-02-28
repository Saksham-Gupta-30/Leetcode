class Solution {
public:
    // bool f(int i, int j, string &p, string &s, vector<vector<int>> &dp) {
    //     if (i < 0 && j < 0) return true;
    //     if (i < 0 && j >= 0) return false;
    //     if (j < 0 && i >= 0) {
    //         for (int k = 0; k <= i; k++) {
    //             if (p[k] != '*') return false;
    //         }
    //         return true;
    //     }
    //     if (dp[i][j] != -1) return dp[i][j];

    //     if (p[i] == s[j] || p[i] == '?') return dp[i][j] = f(i - 1, j - 1, p, s, dp);
    //     if (p[i] == '*') return dp[i][j] = f(i - 1, j, p, s, dp) | f(i, j - 1, p, s, dp);

    //     return dp[i][j] = false;
    // }
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        // vector<vector<bool>> dp(n + 1, vector<bool> (m + 1, false));
        // dp[0][0] = true;
        // for (int j = 1; j <= m; j++) dp[0][j] = false;
        // for (int i = 1; i <= n; i++) {
        //     bool flag = true;
        //     for (int k = 1; k <= i; k++) {
        //         if (p[k - 1] != '*') {
        //             flag = false;
        //             break;
        //         }
        //     }
        //     dp[i][0] = flag;
        // }

        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         if (p[i - 1] == s[j - 1] || p[i - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
        //         else if (p[i - 1] == '*') dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
        //         else dp[i][j] = false;
        //     }
        // }
        
        // return dp[n][m];

        if (p == s) return true;

        vector<bool> prev(m + 1, false), curr(m + 1, false);
        prev[0] = true;
        for (int j = 1; j <= m; j++) prev[j] = false;

        for (int i = 1; i <= n; i++) {
            bool flag = true;
            for (int k = 1; k <= i; k++) {
                if (p[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            curr[0] = flag;

            for (int j = 1; j <= m; j++) {
                if (p[i - 1] == s[j - 1] || p[i - 1] == '?') curr[j] = prev[j - 1];
                else if (p[i - 1] == '*') curr[j] = prev[j] | curr[j - 1];
                else curr[j] = false;
            }
            prev = curr;
        }

        return curr[m];
    }
};
