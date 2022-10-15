class Solution {
public:
    void solution(int a, int b, string x, vector<string>& ans, int n) {
        if (a == n && b == n) {
            ans.emplace_back(x);
            return;
        }
        if (a <= n && a >= b) {
            solution(a + 1, b, x + '(', ans, n);
        }
        if (b <= n && b <= a) {
            solution(a, b + 1, x + ')', ans, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string x;
        solution(0, 0, x, ans, n);
        return ans;
    }
};
