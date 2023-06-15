/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int level = 1;
        int ans = 1;
        bool flag = false;
        int maxSum = root->val;
        queue<vector<TreeNode*>> q;
        q.push({root});
        while (!q.empty()) {
            flag = false;
            auto vec = q.front();
            q.pop();

            vector<TreeNode*> lvl;
            level++;
            int sum = 0;
            for (auto &it: vec) {
                if (it->left) {
                    flag = true;
                    sum += it->left->val;
                    lvl.push_back(it->left);
                }
                if (it->right) {
                    flag = true;
                    sum += it->right->val;
                    lvl.push_back(it->right);
                }
            }
            if (lvl.size()) q.push(lvl);
            if (sum > maxSum && flag) {
                maxSum = sum;
                ans = level;
            }
        }
        return ans;
    }
};
