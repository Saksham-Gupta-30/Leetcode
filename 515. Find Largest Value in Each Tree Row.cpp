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
    vector<int> largestValues(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto it = q.front();
            TreeNode* node = it.first;
            int lvl = it.second;
            q.pop();

            if (lvl == ans.size()) ans.push_back(node->val);
            else {
                ans[lvl] = max(node->val, ans[lvl]);
            }

            if (node->left) q.push({node->left, lvl + 1});
            if (node->right) q.push({node->right, lvl + 1});
        }
        return ans;
    }
};
