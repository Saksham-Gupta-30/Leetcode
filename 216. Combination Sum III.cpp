class Solution {
public:
    void sol(int n, int k, vector<int>& vec, int i, vector<vector<int>>& ans) {
        if (n == 0 && k == 0) {
            ans.push_back(vec);
            return;
        }
        if (i < 10) {
            vec.push_back(i);
            sol(n - i, k - 1, vec, i + 1, ans);
            vec.pop_back();
            sol(n, k, vec, i + 1, ans);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> vis(10, 0);
        vector<int> vec;
        sol(n, k, vec, 1, ans);
        return ans;
    }
};
