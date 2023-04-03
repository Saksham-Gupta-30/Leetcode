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
    int findBottomLeftValue(TreeNode* root) {
        int ans = root->val;
        queue<vector<TreeNode*>> q;
        q.push({root});

        while (!q.empty()) {
            vector<TreeNode*> temp = q.front();
            q.pop();

            ans = temp[0]->val;
            vector<TreeNode*> lvl;
            for (TreeNode* &node: temp) {
                if (node->left) lvl.push_back(node->left);
                if (node->right) lvl.push_back(node->right);
            }
            if (lvl.size()) q.push(lvl);
        }
        return ans;
    }
};
